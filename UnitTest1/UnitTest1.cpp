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

			// ������� ��� ����������
			a[0] = new int[colCount] { 1, 1, 1 }; // 3 �������
			a[1] = new int[colCount] { 2, 2, 3 }; // 2 �������
			a[2] = new int[colCount] { 4, 5, 6 }; // �� �������

			SortRowsByDuplicateCount(a, rowCount, colCount);

			// �������� ����������� ����������
			Assert::AreEqual(4, a[0][0]); // ����� � ���������� ���������� �� ���� ������
			Assert::AreEqual(2, a[1][0]); // ����� � ����� ���������� �� ���� ������
			Assert::AreEqual(1, a[2][0]); // ����� � ������ ���������� �� ���� �������

			// �������� ���'��
			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
