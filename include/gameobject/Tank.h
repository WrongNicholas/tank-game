#ifndef TANK_H
#define TANK_H

#include "gameobject/GameObject.h"

class Tank : public GameObject {
private:
  // Tank Arm Sprite
  sf::Sprite arm;

  // Initialization Functions
  void initializeTankArm(sf::Texture& texture);
public:
  // Constructor
  Tank(std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& tankTexture, sf::Texture& armTexture);

  // Public Functions
  void update(float dt) override;
  void render(std::shared_ptr<sf::RenderWindow> window) override;
};

#endif
