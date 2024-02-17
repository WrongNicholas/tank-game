#ifndef TILEMAP_H
#define TILEMAP_H

#include <box2d/box2d.h>

#include "core/TextureHandler.h"
#include "gameobject/GameObject.h"

class TileMap {
private:
  // Private Variables
  int world_width = 25, world_height = 19;
  std::vector<std::shared_ptr<GameObject>> tiles;
  // Initialization Functions
  void generateTilesFromLevelData(std::shared_ptr<b2World> world, TextureHandler& textureHandler, std::vector<int>& tileData);
public:
  // Constructor
  TileMap(std::shared_ptr<b2World> world, TextureHandler& textureHandler, std::vector<int> tileData);

  // Public Functions
  void render(std::shared_ptr<sf::RenderWindow> window);
};

#endif
