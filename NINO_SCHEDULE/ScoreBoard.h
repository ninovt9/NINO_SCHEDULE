#pragma once

#include "Parser.h"

#include <algorithm> 

namespace ninoSchedule
{
	class ScoreBoard
	{
	public:
		using TeamDict = Parser::TeamDict;

	public:
		ScoreBoard() = default;
		ScoreBoard(TeamDict& teamList);

	public:
		std::vector<Team>		GetTeamList();
		std::string				ToString();

	private:
		void					CreateTeamList(TeamDict teamDict);
		void					Sort();

	private:
		std::vector<Team>		teamList_;

	};

	inline std::vector<Team> ScoreBoard::GetTeamList()
	{
		return teamList_;
	}

	inline void ScoreBoard::CreateTeamList(TeamDict teamDict)
	{
		for (auto each : teamDict)
		{
			teamList_.push_back(each.second);
		}
	}

	inline void ScoreBoard::Sort()
	{
		std::sort(teamList_.rbegin(), teamList_.rend());
	}



}


