#include "pch.h"
#include "CppUnitTest.h"
#include "../pr_07_1_it/pr_07_1_it.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCreate)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** r = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				r[i] = new int[colCount];

			Create(r, rowCount, colCount, 1, 10);
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::IsTrue(r[i][j] >= 1 && r[i][j] <= 10);
				}
			}
			for (int i = 0; i < rowCount; i++)
				delete[] r[i];
			delete[] r;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** r = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				r[i] = new int[colCount];

			r[0][0] = 3; r[1][0] = 9; r[2][0] = 1;
			r[0][1] = 2; r[1][1] = 8; r[2][1] = 7;
			r[0][2] = 5; r[1][2] = 6; r[2][2] = 4;
			Sort(r, rowCount, colCount);
			Assert::IsTrue(r[0][0] <= r[0][1]);
			Assert::IsTrue(r[0][1] <= r[0][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] r[i];
			delete[] r;
		}

		TEST_METHOD(TestCalc)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** r = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				r[i] = new int[colCount];

			r[0][0] = 2; r[0][1] = -3; r[0][2] = 4;
			r[1][0] = 5; r[1][1] = 6; r[1][2] = 7;
			r[2][0] = -1; r[2][1] = 3; r[2][2] = 0;
			int S = 0;
			int k = 0;
			Calc(r, rowCount, colCount, S, k);
			Assert::AreEqual(S, 26);  
			Assert::AreEqual(k, 7); 

			for (int i = 0; i < rowCount; i++)
				delete[] r[i];
			delete[] r;
		}
	};
}
