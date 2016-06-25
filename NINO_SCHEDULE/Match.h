#pragma once

#include "Team.h"

#include <map>

namespace ninoSchedule
{
	class Match
	{
	public:
		using ScoreType = std::pair<int, int>;

	public:
		Match() = default;
		Match(Team winner, Team loser, ScoreType score);

	public:
		bool				Find(Team team);
		bool				Find(Team teamA, Team teamB);

	public:
		Team				GetWinner() const;
		Team				GetLoser() const;
		ScoreType			GetScore() const;

	public:
		std::string			ToString();

	private:
		Team				winner_;						
		Team				loser_;
		ScoreType			score_;		// ±È·Ö
	};

	inline bool Match::Find(Team team)
	{
		return (team == winner_ ||
				team == loser_);
	}

	inline bool Match::Find(Team teamA, Team teamB)
	{
		if (teamA == teamB)
		{
			return false;
		}
		else
		{
			return (Find(teamA) &&
					Find(teamB));
		}
	}

	inline Team Match::GetWinner() const
	{
		return winner_;
	}

	inline Team Match::GetLoser() const
	{
		return loser_;
	}

	inline Match::ScoreType Match::GetScore() const
	{
		return score_;
	}

}




