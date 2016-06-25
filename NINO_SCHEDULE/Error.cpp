#include "Error.h"





namespace ninoSchedule
{
	Error::Error():errorReports_()
	{

	}


	std::string Error::ToString()
	{
		std::string result;

		for (auto error : errorReports_)
		{
			switch (error.first)
			{
			case ErrorType::FILE_ERROR:
				result.append("FileError: " + error.second + "\n");
				break;
			case ErrorType::TOKEN_ERROR:
				result.append("TokenError: " + error.second + "\n");
				break;
			case ErrorType::SYNTAX_ERROR:
				result.append("SyntaxError: " + error.second + "\n");
				break;
			default:
				break;
			}
		}

		return result;
	}
}

