#include "Scanner.h"





namespace ninoSchedule
{
	Scanner::Scanner(std::string fileName)
	{
		stream_ = std::ifstream(fileName);
		if (stream_.fail())
		{
			error_.AddError(ErrorType::FILE_ERROR, "Failed to open file");
		}

	}


	std::vector<Token>	Scanner::GetTokenList()
	{
		std::vector<Token> tokenList;

		while (PeekChar() != -1)
		{
			if (PeekChar() == ' ' || PeekChar() == '\n')
			{
				SkipChar(1);
			}
			else
			{
				tokenList.push_back(GetToken());
			}
		}

		return tokenList;
	}

	Token Scanner::GetToken()
	{
		auto peek = PeekChar();

		if (isalpha(peek))
		{
			return GetStringToken();
		}
		else if (isdigit(peek))
		{
			return GetNumberToken();
		}
		else if (peek == '\t')
		{
			SkipChar(1);
			return Token(TokenType::TAB);
		}
		else if (peek == ':')
		{
			SkipChar(1);
			return Token(TokenType::COLON);
		}
		else
		{
			SkipChar(1);
			return Token(TokenType::UNKNOWN);
		}
	}


	Token Scanner::GetStringToken()
	{
		std::string buffer;
		
		while (isalpha(PeekChar()))
		{
			buffer.push_back(GetChar());
		}

		return GetKeyWordToken(buffer);
	}

	Token Scanner::GetKeyWordToken(const std::string& buffer)
	{
		if (buffer == "group")
		{
			return Token(TokenType::GROUP);
		}
		else if (buffer == "schedule")
		{
			return Token(TokenType::SCHEDULE);
		}
		else
		{
			return Token(TokenType::STRING, buffer);
		}
	}

	Token Scanner::GetNumberToken()
	{
		std::string buffer;

		while (isdigit(PeekChar()))
		{
			buffer.push_back(GetChar());
		}

		return Token(TokenType::INTEGER, NLib::StringToInt(buffer));
		
	}

	Token Scanner::GetOperatorToken()
	{
		if (PeekChar() == '\t')
		{
			return Token(TokenType::TAB);
		}
		else
		{
			return Token(TokenType::COLON);
		}
	}
}