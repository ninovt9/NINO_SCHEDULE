#include "stdafx.h"
#include "CppUnitTest.h"
#include "Parser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoSchedule;

namespace NINO_TEST_SCHEDULE
{
	TEST_CLASS(Test_Parser)
	{
	private:
		std::vector<Token> tokenList_;
		std::vector<Token> errorList_;

	public:

		TEST_METHOD_INITIALIZE(Test_SetUp)
		{
			std::string TEST_PATH = "D:\\code\\Project\\Other\\NINO_SCHEDULE\\NINO_TEST_SCHEDULE\\";
			
			Scanner scanner(std::string(TEST_PATH + "Demo.txt"));
			tokenList_ = scanner.GetTokenList();

			scanner = Scanner(std::string(TEST_PATH + "ErrorForParser.txt"));
			errorList_ = scanner.GetTokenList();
			
		}

		TEST_METHOD_CLEANUP(Test_CleanUp)
		{

		}

		TEST_METHOD(Test_SkipIter)
		{
			Parser parser(tokenList_.begin(), tokenList_.end());
			parser.SkipIter(tokenList_.size() * 2);
		}

		TEST_METHOD(Test_Update)
		{
			// France 1:0 Romania
			Parser parser(tokenList_.begin()+ 14, tokenList_.end());
			parser.AddTeam("France", Team("France"));
			parser.AddTeam("Romania", Team("Romania"));
			parser.Update();

			Team france = parser.FindTeam("France")->second;
			Team romania = parser.FindTeam("Romania")->second;

			Assert::AreEqual(france.GetPoints(), 3,
				L"France -> points");
			Assert::AreEqual(france.GetGoalDifferential(), 1,
				L"France -> diff");
			Assert::AreEqual(romania.GetPoints(), 0,
				L"France -> points");
			Assert::AreEqual(romania.GetGoalDifferential(), -1,
				L"France -> diff");
		}

		TEST_METHOD(Test_HandleTokenList)
		{
			Parser parser(tokenList_.begin(), tokenList_.end());
			parser.HandleTokenList();

			Assert::IsTrue(parser.HasTeam("France"), L"find team -> France");
			Assert::IsTrue(parser.HasTeam("Romania"), L"find team -> Romania");
			Assert::IsTrue(parser.HasTeam("England"), L"find team -> England");
			Assert::IsTrue(parser.HasTeam("Welsh"), L"find team -> Welsh");

			Team france = parser.FindTeam("France")->second;
			Team romania = parser.FindTeam("Romania")->second;
			Team england = parser.FindTeam("England")->second;
			Team welsh = parser.FindTeam("Welsh")->second;

			Assert::AreEqual(france.GetPoints(), 3,
				L"France -> points");
			Assert::AreEqual(france.GetGoalDifferential(), 1,
				L"France -> diff");
			Assert::AreEqual(romania.GetPoints(), 0,
				L"Romania -> points");
			Assert::AreEqual(romania.GetGoalDifferential(), -1,
				L"Romania -> diff");
			Assert::AreEqual(england.GetPoints(), 0,
				L"England -> points");
			Assert::AreEqual(england.GetGoalDifferential(), -5,
				L"England -> diff");
			Assert::AreEqual(welsh.GetPoints(), 3,
				L"Welsh -> points");
			Assert::AreEqual(welsh.GetGoalDifferential(), 5,
				L"Welsh -> diff");
		}

		//TEST_METHOD(Test_HandleTokenList_ForError)
		//{
		//	Parser parser(errorList_.begin(), errorList_.end());
		//	parser.HandleTokenList();

		//	auto report = parser.ErrorReport();
		//	int i = 0;
		//}


	};
}