#include "gameobject/Player.h"

// Constructor
Player::Player(std::shared_ptr<InputHandler> inputHandler, std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& playerTexture, sf::Texture& armTexture) : Tank(world, position, playerTexture, armTexture)
{
  this->inputHandler = inputHandler;  
}

// Private Functions
float Player::getArmTargetRotation()
{
  sf::Vector2i mousePosition = this->inputHandler->getMousePosition();
  sf::Vector2f armPosition = this->arm.getPosition();
  return atan2f(mousePosition.y - armPosition.y, mousePosition.x - armPosition.x) * 180.f / b2_pi;
}

// Public Functions
void Player::update(float dt)
{
  // Player Specific Update
  b2Vec2 inputVector = this->inputHandler->getInputVector();
  this->body->SetLinearVelocity(b2Vec2(inputVector.x * this->speed, inputVector.y * this->speed));  
  
  if (this->inputHandler->getShoot())
  {
    this->shootBullet();
  }

  // GameObject update
  this->Tank::update(dt);
}

void Player::render(std::shared_ptr<sf::RenderWindow> window)
{
  this->Tank::render(window);
}
