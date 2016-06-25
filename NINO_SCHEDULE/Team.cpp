#include "Team.h"




namespace ninoSchedule
{
	Team::Team():name_(""), points_(0), goalDifferential_(0)
	{
		
	}

	Team::Team(std::string name) : name_(name), points_(0), goalDifferential_(0)
	{

	}

	Team::Team(std::string name, int points, int goalDifferential) :
		name_(name), points_(points), goalDifferential_(goalDifferential)
	{

	}

	void Team::Update(int basePoints, int otherPoints)
	{
		auto diff = basePoints - otherPoints;
		
		if (diff > 0)
		{
			points_ += 3;
		}
		else if (diff < 0)
		{
			points_ += 0;
		}
		else
		{
			points_ += 1;
		}

		goalDifferential_ += diff;
	}

}




