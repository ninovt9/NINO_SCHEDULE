

#include <string>


namespace ninoSchedule
{
	enum class TokenType
	{
		INTEGER,
		STRING,
		TAB,
		COLON,
		GROUP,
		SCHEDULE,

		UNKNOWN
	};

	class Token
	{
	public:
		Token();
		Token(TokenType type);
		Token(TokenType type, std::string name);
		Token(TokenType type, int intValue);

	public:
		bool operator==(const Token& other);

	public:
		std::string			GetName() const;
		TokenType			GetType() const;
		int					GetIntValue() const;

	private:
		std::string			name_;
		TokenType			type_;
		int					intValue_;

	};

	inline bool Token::operator==(const Token& other)
	{
		return(
			name_ == other.name_ &&
			type_ == other.type_ &&
			intValue_ == other.intValue_
			);
	}

	inline std::string	Token::GetName() const
	{
		return name_;
	}

	inline TokenType Token::GetType() const
	{
		return type_;
	}

	inline int	Token::GetIntValue() const
	{
		return intValue_;
	}
}




