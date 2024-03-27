#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject/Tank.h"
#include "core/InputHandler.h"

class Player : public Tank 
{
  private:
  // Private Variables
  const float speed = 200.f; 
  std::shared_ptr<InputHandler> inputHandler;

  // Private Functions
  float getArmTargetRotation() override;
public:
  // Constructor
  Player(std::shared_ptr<InputHandler> inputHandler, std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& playerTexture, sf::Texture& armTexture);
  
  // Public Functions
  void update(float dt) override;
  void render(std::shared_ptr<sf::RenderWindow> window) override;
};
#endif
