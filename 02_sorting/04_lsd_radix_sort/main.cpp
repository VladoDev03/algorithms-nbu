#include <iostream>

using namespace std;

void countingSort(int numbers[], int n, int exponent);
void radixSort(int numbers[], int n);
void printArray(int numbers[], int n);

int main()
{
    int n = 0;
    cin >> n;
    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << "Before: ";
    printArray(numbers, n);

    radixSort(numbers, n);

    cout << "After: ";
    printArray(numbers, n);

    return 0;
}

void countingSort(int numbers[], int n, int exponent)
{
    int output[n];
    int counts[10] = {0};

    for (int i = 0; i < n; i++)
    {
        counts[(numbers[i] / exponent) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        counts[i] += counts[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[counts[(numbers[i] / exponent) % 10] - 1] = numbers[i];
        counts[(numbers[i] / exponent) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        numbers[i] = output[i];
    }
}

void radixSort(int numbers[], int n)
{
    int maxNum = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > maxNum)
        {
            maxNum = numbers[i];
        }
    }

    for (int exponent = 1; maxNum / exponent > 0; exponent *= 10)
    {
        countingSort(numbers, n, exponent);
    }
}

void printArray(int numbers[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i];

        if (i < n - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
}
