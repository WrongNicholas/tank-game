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

std::vector<int> LevelDataParser::getTileMapData()
{
  // std::cout << this->jsonData["tilemap"] << std::endl;
  return this->jsonData["tilemap"];
}
