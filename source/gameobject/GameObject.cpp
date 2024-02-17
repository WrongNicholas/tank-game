#include "gameobject/GameObject.h"

// Initialization Functions
void GameObject::initializeBody(std::shared_ptr<b2World> world, b2Vec2 position, b2BodyType bodyType)
{
  b2BodyDef bodyDef;
  bodyDef.type = bodyType;
  bodyDef.position = position;
  bodyDef.linearDamping = 5.f;
  bodyDef.fixedRotation = true;

  this->body = world->CreateBody(&bodyDef);

  b2PolygonShape shape;
  shape.SetAsBox(this->sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &shape;
  fixtureDef.density = 1.f;
  fixtureDef.friction = .1;
  fixtureDef.restitution = 1.f;

  body->CreateFixture(&fixtureDef);
}

void GameObject::initializeSprite(sf::Texture& texture)
{
  // this->sprite.setPosition(this->body->GetPosition().x, this->body->GetPosition().y);
  this->sprite.setTexture(texture);
}

// Constructors
GameObject::GameObject(std::shared_ptr<b2World> world, b2Vec2 position, b2BodyType bodyType, sf::Texture& texture)
{
  // Initialize SFML Sprite
  this->initializeSprite(texture);

  // Initialize Box2D Body (After SFML Sprite to Pull Size Dimensions for FixtureDef)
  this->initializeBody(world, position, bodyType);
  
  // Set Initial Sprite Position
  this->sprite.setPosition(this->body->GetPosition().x, this->body->GetPosition().y);
}

// Accessors
sf::Sprite& GameObject::getSprite()
{
  return this->sprite;
}

// Public Functions
void GameObject::update(float dt)
{
  // Update Sprite
  b2Vec2 bodyPosition = this->body->GetPosition();
  this->sprite.setPosition(bodyPosition.x, bodyPosition.y); 
}
