#include "stdafx.h"
#include "CppUnitTest.h"
#include "Match.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoSchedule;

namespace NINO_TEST_SCHEDULE
{
	TEST_CLASS(Test_Match)
	{
	public:

		TEST_METHOD(Test_Find)
		{
			Team England("England", 0, 0);
			Team Italia("Italia", 0, 0);
			Match match(England, Italia, { 0, 5 });
			Assert::IsTrue(match.Find(England),
				L"England -> true");
			Assert::IsTrue(match.Find(Italia),
				L"Italia -> true");
			Assert::IsTrue(match.Find(England, Italia),
				L"England, Italia -> true");

		}

	};
}