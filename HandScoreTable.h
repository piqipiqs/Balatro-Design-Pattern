#pragma once

#include <unordered_map>
#include <vector>
#include <string>

class HandScoreTable
{
public:
    HandScoreTable();
    ~HandScoreTable();

    void Initialize();
    int GetScore(const std::string& handType) const;
    std::vector<std::string> GetAllHandTypes() const;

private:
    std::unordered_map<std::string, int> scoreTable;
};
