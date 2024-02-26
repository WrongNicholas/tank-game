#include "gameobject/Player.h"

// Constructor
Player::Player(std::shared_ptr<InputHandler> inputHandler, std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& playerTexture) : GameObject(world, position, b2_dynamicBody, playerTexture)
{
  this->inputHandler = inputHandler;  
}

// Public Functions
void Player::update(float dt)
{
  // Player Specific Update
  b2Vec2 inputVector = this->inputHandler->getInputVector();
  this->body->SetLinearVelocity(b2Vec2(inputVector.x * this->speed, inputVector.y * this->speed));  

  // GameObject Update
  this->GameObject::update(dt);
}

void Player::render(std::shared_ptr<sf::RenderWindow> window)
{
  this->GameObject::render(window);
}
