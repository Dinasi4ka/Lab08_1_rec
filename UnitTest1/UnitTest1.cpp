#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab08_1_rec/Lab08_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char string[] = "'ab','+','=', 'c'";
			int count = 2;

			int t = Count(string,0);
			Assert::AreEqual(count, t);

		}
	};
}
