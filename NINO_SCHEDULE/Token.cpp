#include "Token.h"




namespace ninoSchedule
{
	Token::Token() :name_(""), type_(TokenType::UNKNOWN), intValue_(0)
	{

	}

	Token::Token(TokenType type) :
		name_(""), type_(type), intValue_(0)
	{

	}

	Token::Token(TokenType type, std::string name) :
		name_(name), type_(type), intValue_(0)
	{

	}

	Token::Token(TokenType type, int intValue) :
		name_(""), type_(type), intValue_(intValue)
	{

	}
}


