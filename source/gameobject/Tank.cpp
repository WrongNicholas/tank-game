#include "gameobject/Tank.h"

// Initialization Functions
void Tank::initializeTankArm(sf::Texture& texture)
{

}

// Constructor
Tank::Tank(std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& tankTexture, sf::Texture& armTexture)
  : GameObject(world, position, b2_dynamicBody, tankTexture)
{
  
  this->initializeTankArm(armTexture);
}

// Public Functions
void Tank::update(float dt)
{
  
  // Update GameObject
  this->GameObject::update(dt);
}
