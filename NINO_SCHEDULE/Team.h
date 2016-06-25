#pragma once

#include <string>


namespace ninoSchedule
{
	class Team
	{
	public:
		Team();
		Team(std::string name);
		Team(std::string name, int points, int goalDifferential);

	public:
		bool				operator==(const Team& other) const;
		bool				operator<(const Team& other) const;

	public:
		// 更新积分与净胜球
		void				Update(int basePoints, int otherPoints);

	public:
		std::string			GetName() const;
		int					GetPoints() const;
		int					GetGoalDifferential() const;
		std::string			ToString() const;

	private:
		std::string			name_;			
		int					points_;				// 积分
		int					goalDifferential_;		// 净胜球

	};

	inline bool	Team::operator==(const Team& other) const
	{
		return (
			name_ == other.name_ &&
			points_ == other.points_ &&
			goalDifferential_ == other.goalDifferential_
			);
	}

	inline bool Team::operator<(const Team& other) const
	{
		if (points_ == other.points_)
		{
			return (goalDifferential_ < other.goalDifferential_);
		}
		else
		{
			return (points_ < other.points_);
		}
	}

	inline std::string Team::GetName() const
	{
		return name_;
	}

	inline int Team::GetPoints() const
	{
		return points_;
	}

	inline int Team::GetGoalDifferential() const
	{
		return goalDifferential_;
	}

	inline std::string Team::ToString() const
	{
		return std::string("球队：" + name_ + 
			" 积分：" + std::to_string(points_) + 
			" 净胜球：" + std::to_string(goalDifferential_));
	}
}






