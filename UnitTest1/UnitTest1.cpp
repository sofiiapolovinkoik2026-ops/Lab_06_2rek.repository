#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_2recursive/Lab_06_2recursive.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arr[5] = { -12, 40, 5, 0, 18 };

			// Перевірка рекурсивного мінімального
			int minVal = FindMinRec(arr, 5);
			Assert::AreEqual(-12, minVal);

			// Перевірка рекурсивного максимального
			int maxVal = FindMaxRec(arr, 5);
			Assert::AreEqual(40, maxVal);

			// Перевірка середнього арифметичного (-12 + 40) / 2.0 = 14.0
			double avg = CalculateMinMaxAverageRec(arr, 5);
			Assert::AreEqual(14.0, avg);
		}
	};
}