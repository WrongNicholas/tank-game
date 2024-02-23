#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <SFML/Graphics.hpp>

class TextureHandler {
private:
  // Private Functions
  void initializeTextureMap();
  void addTexture(const std::string& name, const std::string& filepath);

  // Texture Map
  std::map<std::string, sf::Texture> textureMap;  
public:
  // Constructor
  TextureHandler();
   
  // Accessors
  sf::Texture& getTexture(const std::string& name);
};

#endif
