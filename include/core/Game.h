#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <box2d/box2d.h>

#include "core/InputHandler.h"
#include "core/TextureHandler.h"
#include "core/Level.h"


class Game {
private:
  // SFML
  std::shared_ptr<sf::RenderWindow> window;
  sf::VideoMode videoMode;
  
  // Handlers
  std::shared_ptr<InputHandler> inputHandler;
  TextureHandler textureHandler;

  // Box2D
  std::shared_ptr<b2World> world;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
   
  // Level
  std::shared_ptr<Level> level; 

  // Initialization Functions
  void initializeVariables();
  void initializeWindow();
  void initializeTextureHandler(); 
  void initializeLevel();
public:
  // Constructors
  Game();
  ~Game();
  
  // Accessors
  const bool running() const;
  TextureHandler& getTextureHandler();  
  
  // Public Functions
  void update(float dt);
  void render();
};

#endif
