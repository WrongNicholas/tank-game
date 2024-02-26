#include "core/Level.h"

// Initialization Functions
void Level::initializeLevelFromData(std::shared_ptr<InputHandler> inputHandler, std::vector<int>& tileData)
{
  float tileSize = 32.f;

  int i = 0, j = 0;
  while (j < this->world_height)
  {
    switch(tileData[i + j * world_width])
    {
      case 1:
        this->createTile(b2Vec2(i * tileSize, j * tileSize));
      break;
      case 2:
        this->createPlayer(inputHandler, b2Vec2(i * tileSize, j * tileSize));
      break;
      case 3:
        this->createEntity(b2Vec2(i * tileSize, j * tileSize));
      break;
      default:
        // Do nothing
      break;
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

void Level::createTile(b2Vec2 position)
{
  this->tiles.push_back(std::make_shared<GameObject>(this->world, position, b2_staticBody, this->textureHandler.getTexture("tile")));
}

void Level::createPlayer(std::shared_ptr<InputHandler> inputHandler, b2Vec2 position)
{
  this->player = std::make_shared<Player>(inputHandler, this->world, position, this->textureHandler.getTexture("player"));
}

void Level::createEntity(b2Vec2 position)
{
  this->entities.push_back(std::make_shared<GameObject>(this->world, position, b2_dynamicBody, this->textureHandler.getTexture("entity")));
}

// Constructor
Level::Level(std::shared_ptr<InputHandler> inputHandler, std::shared_ptr<b2World> world, TextureHandler& textureHandler, std::vector<int> tileData)
  : textureHandler(textureHandler)
{
  this->world = world;
  this->initializeLevelFromData(inputHandler, tileData);
}

// Public Functions
void Level::update(float dt)
{
  // Update Entities
  for (const auto& entity : this->entities)
  {
    entity->update(dt); 
  }

  // If Exists, Update Player
  if (this->player != nullptr)
  {
    this->player->update(dt);
  }
}

void Level::render(std::shared_ptr<sf::RenderWindow> window)
{
  // Render TileMap
  for (const auto& tile : this->tiles)
  {
    tile->render(window);
  }

  // Render Entities
  for (const auto& entity : this->entities)
  { 
    entity->render(window);
  }
  
  // If Exists, Render Player
  if (this->player != nullptr)
  {
    this->player->render(window);
  }
}
