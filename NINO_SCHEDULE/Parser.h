#pragma once

#include "Scanner.h"
#include "Error.h"


#include <map>


namespace ninoSchedule
{
	class Parser
	{
	public:
		using TokenIndex = Scanner::TokenList::iterator;
		using TeamIndex = std::multimap<std::string, Team>::iterator;
		using TeamDict = std::multimap<std::string, Team>;

	public:
		Parser() = default;
		Parser(TokenIndex begin, TokenIndex end);

	public:
		TeamDict				GetTeamDict();

	public:
		void					SkipIter(int count);

	public:
		void					AddTeam(std::string name, Team team);
		bool					HasTeam(std::string name);
		TeamIndex				FindTeam(std::string name);

	public:
		void					Update();
		void					Update(std::string name, int basePoint, int otherPoint);

	public:
		void					HandleTokenList();
		void					HandleGroupStat();
		void					HandleGroupExp(const std::string &groupName);
		void					HandleScheduleStat();
		void					HandleScheduleExp();
		
	public:
		bool					HasSyntaxError();
		std::string				ErrorReport();

	private:
		TokenIndex				iter_;
		TokenIndex				end_;

	private:
		TeamDict				teamDict_;
		std::string				teamName_;
		Error					error_;

	};

	inline std::multimap<std::string, Team> Parser::GetTeamDict()
	{
		return teamDict_;
	}

	inline void Parser::AddTeam(std::string name, Team team)
	{
		teamDict_.insert({ name, team });
	}

	inline bool	Parser::HasTeam(std::string name)
	{
		return (teamDict_.find(name) != teamDict_.end());
	}

	inline Parser::TeamIndex Parser::FindTeam(std::string name)
	{
		return (teamDict_.find(name));
	}

	inline void Parser::Update(std::string name, int basePoint, int otherPoint)
	{
		auto teamIter = FindTeam(name);
		if (teamIter != teamDict_.end())
		{
			teamIter->second.Update(basePoint, otherPoint);
		}
	}

	inline bool Parser::HasSyntaxError()
	{
		return error_.HasError(ErrorType::SYNTAX_ERROR);
	}

	inline std::string Parser::ErrorReport()
	{
		return error_.ToString();
	}


}


