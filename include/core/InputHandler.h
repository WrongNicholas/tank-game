#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <box2d/box2d.h>

class InputHandler {
  private:
    // Private Variables
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event ev;
    
    // KeyMap
    bool KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT;
  public:
    // Constructor
    InputHandler(std::shared_ptr<sf::RenderWindow> window);
    
    // Accessors
    const bool windowShouldClose() const;
    const b2Vec2 getInputVector() const;
    
    // Public Functions
    void pollEvents();
};

#endif
