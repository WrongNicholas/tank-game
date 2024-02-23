#ifndef TILEMAP_H
#define TILEMAP_H

#include <box2d/box2d.h>

#include "core/TextureHandler.h"
#include "gameobject/GameObject.h"
#include "gameobject/Player.h"
#include "core/InputHandler.h"

class Level {
private:
  // Private Variables
  int world_width = 25, world_height = 19;

  std::shared_ptr<b2World> world;
  TextureHandler& textureHandler;

  std::vector<std::shared_ptr<GameObject>> tiles;
  std::vector<std::shared_ptr<GameObject>> entities;
  std::shared_ptr<Player> player;

  // Initialization Functions
  void initializeLevelFromData(std::shared_ptr<InputHandler> inputHandler, std::vector<int>& tileData);
  void createTile(b2Vec2 position);
  void createPlayer(std::shared_ptr<InputHandler> inputHandler, b2Vec2 position);
  void createEntity(b2Vec2 position);
public:
  // Constructor
  Level(std::shared_ptr<InputHandler> inputHandler, std::shared_ptr<b2World> world, TextureHandler& textureHandler, std::vector<int> tileData);

  // Public Functions
  void update(float dt);
  void render(std::shared_ptr<sf::RenderWindow> window);
};

#endif
