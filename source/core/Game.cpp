#include "core/Game.h"
#include "core/LevelDataParser.h"

// Initialization Functions
void Game::initializeVariables()
{
  // Set Pointers to 'nullptr'
  this->window = nullptr;
  this->inputHandler = nullptr;
  this->world = nullptr;
  this->level = nullptr;
}

void Game::initializeWindow()
{
  this->videoMode.height = 608;
  this->videoMode.width = 800;
  this->window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(this->videoMode, "Hello World!", sf::Style::Titlebar | sf::Style::Close));
}

void Game::initializeLevel()
{
  LevelDataParser levelDataParser;
  levelDataParser.loadLevelData(0);
  this->level = std::make_shared<Level>(this->inputHandler, this->world, this->getTextureHandler(), levelDataParser.getData());
}

// Constructors
Game::Game()
{
  // Initialize all not Explicitly Initialized Variables
  this->initializeVariables();
  this->initializeWindow();

  this->inputHandler = std::make_shared<InputHandler>(this->window);
  this->world = std::make_shared<b2World>(b2Vec2(0.f, 0.f));
  this->initializeLevel();  
}

Game::~Game() 
{
  // Do nothing (for now)
}

// Accessors
const bool Game::running() const
{
  return this->window->isOpen();
}

TextureHandler& Game::getTextureHandler()
{
  return this->textureHandler;
}

// Public Functions
void Game::update(float dt)
{
  // Poll InputHandler
  this->inputHandler->pollEvents();
  
  // Step Box2D World
  this->world->Step(dt, this->velocityIterations, this->positionIterations);
  
  // Update Level
  if (this->level != nullptr)
  {
    this->level->update(dt);
  }
}

void Game::render()
{
  // Refresh Window
  this->window->clear(sf::Color::White);

  // Draw Level
  if (this->level != nullptr)
  {
    this->level->render(this->window);
  }

  // Display Finished Render
  this->window->display();
}
