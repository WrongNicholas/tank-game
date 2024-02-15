#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <SFML/Graphics.hpp>

class TextureHandler {
  private:
    // Texture Map
    std::map<std::string, sf::Texture> textureMap;
    
  public:
    // Constructor
    TextureHandler();
    
    // Public Functions
    void addTexture(const std::string& name, const std::string& filepath);
    
    // Accessors
    sf::Texture& getTexture(const std::string& name);
};

#endif
