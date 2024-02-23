#include <fstream>

#include "core/LevelDataParser.h"

// Constructor
LevelDataParser::LevelDataParser()
{

}

// Public Functions
void LevelDataParser::loadLevelData(const std::string& filepath)
{
  std::ifstream file(filepath);

  file >> this->jsonData;
}

void LevelDataParser::loadLevelData(const int& levelNumber)
{
  this->loadLevelData("resources/levels/" + std::to_string(levelNumber) + ".json");
}

std::vector<int> LevelDataParser::getData()
{
  // std::cout << this->jsonData["tilemap"] << std::endl;
  return this->jsonData["tilemap"];
}
