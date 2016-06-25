#include "stdafx.h"
#include "CppUnitTest.h"
#include "ScoreBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoSchedule;

namespace NINO_TEST_SCHEDULE
{
	TEST_CLASS(Test_ScoreBoard)
	{
	private:
		std::multimap<std::string, Team> teamList_;

	public:

		TEST_METHOD_INITIALIZE(Test_SetUp)
		{
			std::string TEST_PATH = "D:\\code\\Project\\Other\\NINO_SCHEDULE\\NINO_TEST_SCHEDULE\\";
			Scanner scanner(std::string(TEST_PATH + "Demo.txt"));
			auto tokenList_ = scanner.GetTokenList();

			Parser parser(tokenList_.begin(), tokenList_.end());
			teamList_ = parser.GetTeamDict();
		}

		TEST_METHOD_CLEANUP(Test_CleanUp)
		{

		}

		TEST_METHOD(Test_Sort)
		{
			ScoreBoard scoreBoard(teamList_);
			auto teamList = scoreBoard.GetTeamList();
			
			Assert::AreEqual(teamList[0].GetName(), std::string("Welsh"));
			Assert::AreEqual(teamList[1].GetName(), std::string("France"));
			Assert::AreEqual(teamList[2].GetName(), std::string("Romania"));
			Assert::AreEqual(teamList[3].GetName(), std::string("England"));
		}

	};
}