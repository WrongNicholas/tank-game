#include <iostream>

#include "core/TextureHandler.h"

// Constructor
TextureHandler::TextureHandler()
{

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
  return this->textureMap.at(name);
}
