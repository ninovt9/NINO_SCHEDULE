#pragma once

#include "Error.h"
#include "Team.h"
#include "Token.h"
#include "NConvert.h"

#include <string>
#include <vector>
#include <fstream>


namespace ninoSchedule
{
	class Scanner
	{
	public:
		using TokenList = std::vector<Token>;

	public:
		Scanner() = default;
		Scanner(std::string fileName);

	public:
		char				GetChar();

		void				SkipChar(int count);

		char				PeekChar();

	public:
		Token				GetToken();
		std::vector<Token>	GetTokenList();

	public:
		Token				GetStringToken();
		Token				GetKeyWordToken(const std::string& buffer);
		Token				GetNumberToken();
		Token				GetOperatorToken();

	public:
		bool				HasFileError();

	private:
		std::ifstream		stream_;
		Error				error_;
		
	};

	inline char Scanner::GetChar()
	{
		return stream_.get();
	}

	inline void Scanner::SkipChar(int count)
	{
		for (int i = 0; i != count; ++i)
		{
			GetChar();
		}
	}

	inline char Scanner::PeekChar()
	{
		return stream_.peek();
	}

	inline bool Scanner::HasFileError()
	{
		return error_.HasError(ErrorType::FILE_ERROR);
	}

}