#ifndef LEVELDATAPARSER_H
#define LEVELDATAPARSER_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

class LevelDataParser {
private:
  json jsonData;
public:
  // Constructor
  LevelDataParser();

  // Public Functions
  void loadLevelData(const std::string& filepath);
  void loadLevelData(const int& levelNumber);
  std::vector<int> getData();
};

#endif
