#pragma once

#include <map>
#include <string>
#include <vector>



namespace ninoSchedule
{
	enum class ErrorType
	{
		FILE_ERROR,
		TOKEN_ERROR,
		SYNTAX_ERROR,
	};

	class Error
	{
	public:
		using ErrorList = std::multimap<ErrorType, std::string>;
		
	public:
		Error();

	public:
		bool			HasError() const;
		bool			HasError(ErrorType) const;

	public:
		void			AddError(ErrorType type, std::string msg);
		std::string		ToString();

	private:
		ErrorList		errorReports_;
	};

	inline bool Error::HasError() const
	{
		return (errorReports_.size() != 0);
	}

	inline bool Error::HasError(ErrorType type) const
	{
		return (errorReports_.find(type) != errorReports_.end());
	}

	inline void Error::AddError(ErrorType type, std::string msg)
	{
		errorReports_.insert({ type, msg });
	}
}



