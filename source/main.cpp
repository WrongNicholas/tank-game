#include <chrono>
#include "core/Game.h"

int main()
{
  Game game;
  auto previousTime = std::chrono::high_resolution_clock::now();
  while(game.running())
  {
    auto currentTime = std::chrono::high_resolution_clock::now();
    float dt = std::chrono::duration<float>(currentTime - previousTime).count();
    previousTime = currentTime;

    // Update Game
    game.update(dt);

    // Render Game
    game.render();
  }

  return 0;
}
