#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

// Функція для створення матриці
void Input(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

// Функція для виведення матриці
void Print(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

// Функція для підрахунку кількості однакових елементів у рядку
int CountDuplicatesInRow(int* row, int colCount) {
    int maxCount = 0;
    for (int i = 0; i < colCount; i++) {
        int count = 0;
        for (int j = 0; j < colCount; j++) {
            if (row[i] == row[j])
                count++;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

// Функція для упорядкування рядків за кількістю однакових елементів
void SortRowsByDuplicateCount(int** a, const int rowCount, const int colCount) {
    vector<pair<int, int*>> rowsWithCount; // зберігаємо пари (кількість однакових елементів, вказівник на рядок)

    for (int i = 0; i < rowCount; i++) {
        int count = CountDuplicatesInRow(a[i], colCount);
        rowsWithCount.push_back({ count, a[i] });
    }

    sort(rowsWithCount.begin(), rowsWithCount.end(), [](pair<int, int*> a, pair<int, int*> b) {
        return a.first < b.first; // сортуємо за зростанням кількості однакових елементів
        });

    // Оновлюємо початкову матрицю після сортування
    for (int i = 0; i < rowCount; i++) {
        a[i] = rowsWithCount[i].second;
    }
}

// Функція для пошуку першого стовпця без від'ємних елементів
int FindFirstColumnWithoutNegatives(int** a, const int rowCount, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        bool hasNegative = false;
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative)
            return j; // Повертаємо індекс першого стовпця без від'ємних значень
    }
    return -1; // Якщо такого стовпця немає
}

int main() {
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Введення матриці
    Input(a, rowCount, colCount);

    // Виведення матриці перед сортуванням
    cout << "Matrix before sorting:" << endl;
    Print(a, rowCount, colCount);

    // Сортування рядків
    SortRowsByDuplicateCount(a, rowCount, colCount);

    // Виведення матриці після сортування
    cout << "Matrix after sorting by duplicate count:" << endl;
    Print(a, rowCount, colCount);

    // Пошук першого стовпця без від'ємних елементів
    int firstNonNegativeColumn = FindFirstColumnWithoutNegatives(a, rowCount, colCount);
    if (firstNonNegativeColumn != -1)
        cout << "First column without negatives: " << firstNonNegativeColumn + 1 << endl;
    else
        cout << "No column without negatives found." << endl;

    // Очищення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
