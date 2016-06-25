#include "Parser.h"




namespace ninoSchedule
{
	Parser::Parser(TokenIndex begin, TokenIndex end):iter_(begin), end_(end)
	{
		HandleTokenList();
	}

	void Parser::SkipIter(int count)
	{
		for (int i = 0; i != count; ++i)
		{
			if (iter_ + 1 != end_)
			{
				iter_++;
			}
		}
	}

	void Parser::Update()
	{
		std::string leftName = iter_->GetName();
		std::string rightName = (iter_ + 4)->GetName();

		int leftPoint = (iter_ + 1)->GetIntValue();
		int rightPoint = (iter_ + 3)->GetIntValue();

		Update(leftName, leftPoint, rightPoint);
		Update(rightName, rightPoint, leftPoint);
	}

	void Parser::HandleTokenList()
	{
		for(int i = 0; i != 5; ++i)
		{
			if (iter_->GetType() == TokenType::GROUP)
			{
				SkipIter(1);
				HandleGroupStat();
			}
			else if (iter_->GetType() == TokenType::SCHEDULE)
			{
				SkipIter(1);
				HandleScheduleStat();
			}
			else
			{
				error_.AddError(ErrorType::SYNTAX_ERROR, "error title");
			}
		}

	}

	void Parser::HandleGroupStat()
	{
		if (iter_->GetType() == TokenType::STRING)
		{
			auto groupName = iter_->GetName();
			SkipIter(1);
			HandleGroupExp(groupName);
		}
		else
		{
			error_.AddError(ErrorType::SYNTAX_ERROR, "error title");
		}
	}

	void Parser::HandleGroupExp(const std::string &groupName)
	{
		auto condition = [](TokenIndex iter)
		{
			return (iter->GetType() == TokenType::TAB && (iter + 1)->GetType() == TokenType::STRING);
		};

		for (; condition(iter_); SkipIter(2))
		{
			auto teamName = (iter_ + 1)->GetName();
			AddTeam(teamName, Team(teamName));
		}
	}

	void Parser::HandleScheduleStat()
	{
		while (iter_->GetType() == TokenType::TAB)
		{
			SkipIter(1);
			HandleScheduleExp();
		}
	}
	
	void Parser::HandleScheduleExp()
	{

		if (iter_->GetType() == TokenType::STRING &&
			(iter_ + 1)->GetType() == TokenType::INTEGER &&
			(iter_ + 2)->GetType() == TokenType::COLON &&
			(iter_ + 3)->GetType() == TokenType::INTEGER &&
			(iter_ + 4)->GetType() == TokenType::STRING)
		{
			Update();
			SkipIter(5);

		}
		else
		{
			error_.AddError(ErrorType::SYNTAX_ERROR, "error schedule list");
		}



	}

}
