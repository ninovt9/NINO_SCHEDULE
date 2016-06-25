#include "stdafx.h"
#include "CppUnitTest.h"
#include "Team.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoSchedule;

namespace NINO_TEST_SCHEDULE
{		
	TEST_CLASS(Test_Team)
	{
	public:
		
		TEST_METHOD(Test_OperatorLessThan)
		{
			Assert::IsTrue(Team("Èýß÷", 5, 10) < Team("°åÑ¼", 7, 10),
				L"Èýß÷ < °åÑ¼ -> true");
			Assert::IsFalse(Team("Èýß÷", 8, 10) < Team("°åÑ¼", 7, 10),
				L"Èýß÷ < °åÑ¼ -> false");
			Assert::IsTrue(Team("Èýß÷", 7, 9) < Team("°åÑ¼", 7, 10),
				L"the same points -> true");
			Assert::IsFalse(Team("Èýß÷", 7, 12) < Team("°åÑ¼", 7, 10),
				L"the same points -> false");

		}

		TEST_METHOD(Test_OperatorEqualTo)
		{
			Assert::IsTrue(Team("Èýß÷", 5, 10) == Team("Èýß÷", 5, 10));
			Assert::IsFalse(Team("Èýß÷", 5, 10) == Team("Èýß÷", 7, 10));
		}
		
		TEST_METHOD(Test_Update)
		{
			Team team;

			// first  : 5-1
			// second : 1-2
			// third  : 2-2
			team = Team("England");
			team.Update(5, 1);				
			Assert::AreEqual(team.GetPoints(), 3, 
				L"first points -> 3");
			Assert::AreEqual(team.GetGoalDifferential(), 4,
				L"first goaldiff -> 4");
			
			team.Update(1, 2);
			Assert::AreEqual(team.GetPoints(), 3,
				L"second points -> 3");
			Assert::AreEqual(team.GetGoalDifferential(), 3,
				L"second goaldiff -> 3");

			team.Update(2, 2);
			Assert::AreEqual(team.GetPoints(), 4,
				L"second points -> 4");
			Assert::AreEqual(team.GetGoalDifferential(), 3,
				L"second goaldiff -> 3");
		}

	};
}