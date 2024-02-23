#include <iostream>

#include "core/TextureHandler.h"

// Initialization Functions
void TextureHandler::initializeTextureMap()
{
  this->addTexture("entity", "resources/textures/entity.png");
  this->addTexture("tile", "resources/textures/simple_tile.png");
  this->addTexture("player", "resources/textures/player.png");
}

// Constructor
TextureHandler::TextureHandler()
{
  this->initializeTextureMap();
}

void TextureHandler::addTexture(const std::string& name, const std::string& filepath)
{
  sf::Texture texture;
  if (texture.loadFromFile(filepath))
  {
    this->textureMap[name] = texture;
  }
  else
  {
    std::cerr << "Unable to load texture '" << filepath << "'" << std::endl;
  }
}

sf::Texture& TextureHandler::getTexture(const std::string& name)
{
  if (!(this->textureMap.count(name)))
    std::cerr << "Unable to find texture '" << name << "'" << std::endl;
  return this->textureMap.at(name);
}
