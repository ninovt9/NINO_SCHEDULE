#include "ScoreBoard.h"




namespace ninoSchedule
{

	ScoreBoard::ScoreBoard(TeamDict& teamDict)
	{
		CreateTeamList(teamDict);
		Sort();
	}

	std::string ScoreBoard::ToString()
	{
		std::string result;

		for (size_t i = 0; i != teamList_.size(); ++i)
		{
			result.append(std::to_string(i) + std::string(".") + teamList_[i].GetName() + std::string("\n"));

		}

		return result;
	}

}





