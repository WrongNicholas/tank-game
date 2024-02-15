#include <core/Game.h>

// Initialization Functions
void Game::initializeVariables()
{
  // Set Pointers to 'nullptr'
  this->window = nullptr;
  this->inputHandler = nullptr;
  this->world = nullptr;
}

void Game::initializeWindow()
{
  this->videoMode.height = 600;
  this->videoMode.width = 800;
  this->window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(this->videoMode, "Hello World!", sf::Style::Titlebar | sf::Style::Close));
}

void Game::initializeTextureHandler()
{
  // Should probably automate this later
  this->textureHandler.addTexture("player", "resources/player.png");
  this->textureHandler.addTexture("entity", "resources/entity.png");
}

// GameObject Creation
void Game::createPlayer(float x, float y)
{
  b2Vec2 position(x, y);
  this->player = std::make_shared<Player>(this->inputHandler, this->world, position, this->textureHandler.getTexture("player"));
}

void Game::createEntity(float x, float y)
{
  b2Vec2 position(x, y);
  std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>(this->world, position, b2_dynamicBody, this->textureHandler.getTexture("entity"));
  this->gameObjects.push_back(gameObject);
}

// Constructors
Game::Game()
{
  // Initialize all not Explicitly Initialized Variables
  this->initializeVariables();
  this->initializeWindow();

  this->inputHandler = std::make_shared<InputHandler>(this->window);
  this->world = std::make_shared<b2World>(b2Vec2(0.f, 0.f));

  this->initializeTextureHandler();

  // GameObjects
  this->createPlayer(10.f, 10.f);
  this->createEntity(100.f, 100.f);
}

Game::~Game()
{
  
}

// Accessors
const bool Game::running() const
{
  return this->window->isOpen();
}

// Public Functions
void Game::update(float dt)
{
  // Poll InputHandler
  this->inputHandler->pollEvents();
  
  // Step Box2D World
  this->world->Step(dt, this->velocityIterations, this->positionIterations);

  // Update All GameObjects in Vector
  for (const auto& gameObject : this->gameObjects)
  {
    gameObject->update(dt);
  }

  // Update Player
  this->player->update(dt);
}

void Game::render()
{
  // Refresh Window
  this->window->clear(sf::Color::Black);
  
  // Draw All GameObjects in Vector
  for (const auto& gameObject : this->gameObjects)
  {
    this->window->draw(gameObject->getSprite());
  }
  
  // Draw Player
  this->window->draw(player->getSprite());

  // Display Finished Render
  this->window->display();
}
