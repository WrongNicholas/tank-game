#include "core/TileMap.h"

// Initialization Functions
void TileMap::generateTilesFromLevelData(std::shared_ptr<b2World> world, TextureHandler& textureHandler, std::vector<int>& tileData)
{
  float tileSize = 32.f;

  int i = 0, j = 0;
  while (j < this->world_height)
  {
    if (tileData[i + j * world_width] == 1)
    {
      this->tiles.push_back(std::make_shared<GameObject>(world, b2Vec2(i * tileSize, j * tileSize), b2_staticBody, textureHandler.getTexture("tile")));
    }
    if (i < this->world_width)
    {
      i++;
    }
    else
    {
      i = 0;
      j++;
    }
  }
  
}

// Constructor
TileMap::TileMap(std::shared_ptr<b2World> world, TextureHandler& textureHandler, std::vector<int> tileData)
{
  this->generateTilesFromLevelData(world, textureHandler, tileData);
}

// Public Functions
void TileMap::render(std::shared_ptr<sf::RenderWindow> window)
{
  for (const auto& tile : this->tiles)
  {
    window->draw(tile->getSprite());
  }
}
