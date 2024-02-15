#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class GameObject {
  private:
    // Sprite Variables
    sf::Sprite sprite;
    
    // Initialization Functions
    void initializeBody(std::shared_ptr<b2World> world, b2Vec2 position, b2BodyType bodyType);
    void initializeSprite(sf::Texture& texture);
    void initializeFixtureDef();
  protected:
    // Protected Variables
    b2Body* body;
  public:
    // Constructor
    GameObject(std::shared_ptr<b2World> world, b2Vec2 position, b2BodyType bodyType, sf::Texture& texture);
    
    // Accessors
    sf::Sprite& getSprite();
    b2Body& getBody();
    
    // Public Functions
    virtual void update(float dt);
};

#endif
