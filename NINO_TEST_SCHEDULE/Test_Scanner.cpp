#include "stdafx.h"
#include "CppUnitTest.h"
#include "Scanner.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoSchedule;

namespace NINO_TEST_SCHEDULE
{
	TEST_CLASS(Test_Scanner)
	{
	private:
		Scanner wrong_;
		Scanner empty_;
		Scanner demo_;

	public:

		TEST_METHOD_INITIALIZE(Test_SetUp)
		{
			std::string TEST_PATH = "D:\\code\\Project\\Other\\NINO_SCHEDULE\\NINO_TEST_SCHEDULE\\";
			wrong_ = Scanner("wrong.txt");
			empty_ = Scanner(std::string(TEST_PATH + "Empty.txt"));
			demo_ = Scanner(std::string(TEST_PATH + "Demo.txt"));

		}

		TEST_METHOD_CLEANUP(Test_CleanUp)
		{
			
		}

		TEST_METHOD(Test_Class_OpenFile)
		{
			Assert::IsTrue(wrong_.HasFileError(),
				L"fail file path");
			Assert::IsFalse(empty_.HasFileError(),
				L"correct file path");
		}

		TEST_METHOD(Test_SkipChar)
		{
			// a total of 98 byte in file
			demo_.SkipChar(97);
			Assert::AreEqual(demo_.GetChar(), 'h',
				L"the last byte");
			Assert::AreEqual(demo_.GetChar(), char(-1),
				L"out of range");
		}

		TEST_METHOD(Test_Class_GetToken)
		{
			
			Assert::IsTrue(demo_.GetToken() == Token(TokenType::GROUP),
				L"the first token");
			demo_.SkipChar(88);
			Assert::IsTrue(demo_.GetToken() == Token(TokenType::STRING, "Welsh"),
				L"the last token");
			Assert::IsTrue(demo_.GetToken() == Token(TokenType::UNKNOWN),
				L"out of range");

			
			// limit test
			Assert::IsTrue(empty_.GetToken() == Token(TokenType::UNKNOWN),
				L"limit test");
		}

		TEST_METHOD(Test_Class_GetTokenList)
		{
			std::vector<Token> tokenList = demo_.GetTokenList();
			Assert::IsTrue(tokenList[1] == Token(TokenType::STRING, "A"),
				L"skip the space");
			Assert::IsTrue(tokenList[2] == Token(TokenType::TAB),
				L"skip the linebreak");
			Assert::IsFalse(std::find(tokenList.begin(), tokenList.end(), Token(TokenType::UNKNOWN))
				!= tokenList.end(), L"unknown token");
			Assert::AreEqual(tokenList.size(), size_t(25),
				L"number of token");
		}

		TEST_METHOD(Test_Class_GetStringToken_ForKeyWord)
		{
			// group and schedule
			Assert::IsTrue(demo_.GetStringToken() == Token(TokenType::GROUP),
				L"keyword -> group");
			demo_.SkipChar(46);
			Assert::IsTrue(demo_.GetStringToken() == Token(TokenType::SCHEDULE),
				L"keyword -> schedule");
		}

		TEST_METHOD(Test_Class_GetStringToken)
		{
			demo_.SkipChar(6);
			Assert::IsTrue(demo_.GetStringToken() == Token(TokenType::STRING, "A"),
				L"string -> 'A'");
			demo_.SkipChar(2);
			Assert::IsTrue(demo_.GetStringToken() == Token(TokenType::STRING, "France"),
				L"string -> 'France'");
		}

		TEST_METHOD(Test_Class_GetNumberToken)
		{
			demo_.SkipChar(68);
			Assert::IsTrue(demo_.GetNumberToken() == Token(TokenType::INTEGER, 1),
				L"integer -> 1");
			demo_.SkipChar(1);
			Assert::IsTrue(demo_.GetNumberToken() == Token(TokenType::INTEGER, 0),
				L"integer -> 0");
		}

		TEST_METHOD(Test_Class_GetOperatorToken)
		{
			demo_.SkipChar(8);
			Assert::IsTrue(demo_.GetOperatorToken() == Token(TokenType::TAB),
				L"operator -> tab");
			demo_.SkipChar(6);
			Assert::IsTrue(demo_.GetOperatorToken() == Token(TokenType::COLON),
				L"operator -> ':'");
		}
	};
}