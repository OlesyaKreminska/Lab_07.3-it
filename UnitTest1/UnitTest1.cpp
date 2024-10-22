#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3-it/Lab_07.3-it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest073
{
	TEST_CLASS(UnitTest073)
	{
	public:

		TEST_METHOD(TestSortRowsByDuplicateCount)
		{
			int rowCount = 3, colCount = 3;
			int** a = new int* [rowCount];

			// Матриця для сортування
			a[0] = new int[colCount] { 1, 1, 1 }; // 3 однакові
			a[1] = new int[colCount] { 2, 2, 3 }; // 2 однакові
			a[2] = new int[colCount] { 4, 5, 6 }; // всі унікальні

			SortRowsByDuplicateCount(a, rowCount, colCount);

			// Перевірка правильного сортування
			Assert::AreEqual(4, a[0][0]); // рядок з унікальними елементами має бути першим
			Assert::AreEqual(2, a[1][0]); // рядок з двома однаковими має бути другим
			Assert::AreEqual(1, a[2][0]); // рядок з трьома однаковими має бути останнім

			// Очищення пам'яті
			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
