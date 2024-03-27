#ifndef TANK_H
#define TANK_H

#include "gameobject/GameObject.h"

class Tank : public GameObject 
{
protected:
  // Tank Arm Sprite
  sf::Sprite arm;
  std::shared_ptr<b2World> world;

  // Initialization Functions
  void initializeTankArm(sf::Texture& texture);
  
  // Protected Functions 
  virtual float getArmTargetRotation();
  void shootBullet();
public:
  // Constructor
  Tank(std::shared_ptr<b2World> world, b2Vec2 position, sf::Texture& tankTexture, sf::Texture& armTexture);
  
  // Public Functions
  void update(float dt) override;
  void render(std::shared_ptr<sf::RenderWindow> window) override;
};

#endif
