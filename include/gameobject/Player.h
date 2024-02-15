#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject/GameObject.h"
#include "core/InputHandler.h"

class Player : public GameObject
{
  private:
    // Private Variables
    const float speed = 400.f; 
    // InputHandler
    std::shared_ptr<InputHandler> inputHandler;
  public:
    // Constructor
    Player(std::shared_ptr<InputHandler> inputHandler, std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& playerTexture);

    // Public Functions
    void update(float dt) override;
};
#endif
