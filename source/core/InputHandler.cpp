#include "core/InputHandler.h"
#include <SFML/Window/Keyboard.hpp>

// Constructor
InputHandler::InputHandler(std::shared_ptr<sf::RenderWindow> window)
{
  this->window = window;
}

// Accessors
const bool InputHandler::windowShouldClose() const
{
  return this->ev.type == sf::Event::Closed || (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape);
}

const b2Vec2 InputHandler::getInputVector() const
{
  // Calculate InputVector using static_cast (Convert bool values to integers)
  b2Vec2 inputVector = b2Vec2(
    static_cast<float>(KEY_RIGHT) - static_cast<float>(KEY_LEFT),
    static_cast<float>(KEY_DOWN) - static_cast<float>(KEY_UP)
  );

  // Normalize Input Vector if needed
  float magnitude = sqrt(pow(inputVector.x, 2) + pow(inputVector.y, 2));
  if (magnitude != 0)
    return b2Vec2(inputVector.x / magnitude, inputVector.y / magnitude);
  return inputVector;
}

// Public Functions
void InputHandler::pollEvents()
{
  while(this->window->pollEvent(this->ev))
  {
    // Handle Window Close
    if (this->windowShouldClose())
    {
      this->window->close();
    }

    // Handle KeyPressed
    if (this->ev.type == sf::Event::KeyPressed)
    {
      switch(this->ev.key.code)
      {
        case sf::Keyboard::W:
          KEY_UP = true;
        break;
        case sf::Keyboard::S:
          KEY_DOWN = true;
        break;
        case sf::Keyboard::A:
          KEY_LEFT = true;
        break;
        case sf::Keyboard::D:
          KEY_RIGHT = true;
        break;
        default:
          // Do nothing
        break;
      }
    }
    
    // Handle KeyReleased
    if (this->ev.type == sf::Event::KeyReleased)
    {
      switch(this->ev.key.code)
      {
        case sf::Keyboard::W:
          KEY_UP = false;
        break;
        case sf::Keyboard::S:
          KEY_DOWN = false;
        break;
        case sf::Keyboard::A:
          KEY_LEFT = false;
        break;
        case sf::Keyboard::D:
          KEY_RIGHT = false;
        break;
        default:
          // Do nothing
        break;
      }
    }
  }
}
