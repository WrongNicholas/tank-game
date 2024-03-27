#include "gameobject/Tank.h"

// Initialization Functions
void Tank::initializeTankArm(sf::Texture& texture)
{
  this->arm.setTexture(texture);
  this->arm.setOrigin(0, this->arm.getGlobalBounds().height / 2);
}

float Tank::getArmTargetRotation()
{
  return 0.f;
}

#include <iostream>
void Tank::shootBullet()
{
  std::cout << "Shoot!" << std::endl;
}

// Constructor
Tank::Tank(std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& tankTexture, sf::Texture& armTexture) : GameObject(world, position, b2_dynamicBody, tankTexture)
{
  this->world = world;  
  this->initializeTankArm(armTexture);
}

// Public Functions
void Tank::update(float dt)
{
  // BEGIN TANK BODY ROTATION (NEED TO REWORK)
  b2Vec2 velocity = this->getBody()->GetLinearVelocity();

  float targetRotation = atan2f(velocity.y, velocity.x) * 180.f/b2_pi;
  
  if (targetRotation < 0.f)
  {
    targetRotation += 360.f;
  }

  float currentRotation = this->sprite.getRotation();

  float rotationSpeed = 0.1f;

  float firstPossibleAngle = targetRotation;
  float secondPossibleAngle = targetRotation + 180;
  if (secondPossibleAngle >= 360.f)
  {
    secondPossibleAngle -= 360.f;
  }
  if (firstPossibleAngle >= 360.f)
  {
    firstPossibleAngle -= 360.f;
  }

  // std::cout << firstPossibleAngle << ", " << secondPossibleAngle << std::endl;
  switch ((int)((firstPossibleAngle - currentRotation - secondPossibleAngle - currentRotation)/abs(firstPossibleAngle - secondPossibleAngle)))
  {
    case 1:
      targetRotation = secondPossibleAngle;
    break;
    case 0:
      targetRotation = secondPossibleAngle;
      break;
    case -1:
      targetRotation = firstPossibleAngle;
    break;
  }
  
  float rotation = std::lerp(currentRotation, targetRotation, dt/rotationSpeed);

  if (velocity != b2Vec2_zero)
    this->sprite.setRotation(rotation);
  // END TANK BODY ROTATION

  // Tank Arm Position and Rotation
  this->arm.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y);
  this->arm.setRotation(this->getArmTargetRotation()); 

  // Call GameObject Update
  this->GameObject::update(dt);
}

void Tank::render(std::shared_ptr<sf::RenderWindow> window)
{
  // Call GameObject Render
  this->GameObject::render(window);
  window->draw(arm);
}
