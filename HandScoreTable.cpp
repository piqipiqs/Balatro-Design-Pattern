#include "HandScoreTable.h"

HandScoreTable::HandScoreTable()
{
}

HandScoreTable::~HandScoreTable()
{
}

void HandScoreTable::Initialize()
{
}

int HandScoreTable::GetScore(const std::string& handType) const
{
    auto it = scoreTable.find(handType);
    if (it != scoreTable.end())
        return it->second;
    return 0;
}


std::vector<std::string> HandScoreTable::GetAllHandTypes() const
{
    std::vector<std::string> result;
    result.reserve(scoreTable.size());
    for (const auto& p : scoreTable)
        result.push_back(p.first);
    return result;
}

