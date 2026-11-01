// Lab_06_2_rec.cpp
// Половінко Софія 
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів рекурсивними способами.
// Варіант 13

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивна функція формування масиву
void CreateArrayRec(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i < size)
    {
        a[i] = Low + rand() % (High - Low + 1);
        CreateArrayRec(a, size, Low, High, i + 1);
    }
}

// Рекурсивна функція виведення масиву
void PrintArrayRec(const int* a, const int size, int i = 0)
{
    if (i < size)
    {
        cout << setw(5) << a[i];
        PrintArrayRec(a, size, i + 1);
    }
    else
    {
        cout << endl;
    }
}

// Рекурсивна функція пошуку мінімального елемента
int FindMinRec(const int* a, const int size, int i = 1, int minVal = 0)
{
    if (i == 1) minVal = a[0];
    if (i >= size) return minVal;

    if (a[i] < minVal)
        minVal = a[i];

    return FindMinRec(a, size, i + 1, minVal);
}

// Рекурсивна функція пошуку максимального елемента
int FindMaxRec(const int* a, const int size, int i = 1, int maxVal = 0)
{
    if (i == 1) maxVal = a[0];
    if (i >= size) return maxVal;

    if (a[i] > maxVal)
        maxVal = a[i];

    return FindMaxRec(a, size, i + 1, maxVal);
}

// Рекурсивна функція обчислення середнього арифметичного Max та Min
double CalculateMinMaxAverageRec(const int* a, const int size)
{
    int minVal = FindMinRec(a, size);
    int maxVal = FindMaxRec(a, size);
    return (minVal + maxVal) / 2.0;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -20;
    int High = 50;

    CreateArrayRec(a, n, Low, High);

    cout << "Sformovanyi masiv (Recursive):" << endl;
    PrintArrayRec(a, n);

    int minVal = FindMinRec(a, n);
    int maxVal = FindMaxRec(a, n);
    double avg = CalculateMinMaxAverageRec(a, n);

    cout << "\nMin element = " << minVal << endl;
    cout << "Max element = " << maxVal << endl;
    cout << "Serednye aryfmetychne (Min + Max) / 2 = " << fixed << setprecision(2) << avg << endl;

    return 0;
}