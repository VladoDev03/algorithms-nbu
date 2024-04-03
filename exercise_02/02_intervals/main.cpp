#include <iostream>

using namespace std;

void sortWithIntervals(int numbers[], int n);
void sortWithIntervalsInPlace(int numbers[], int n);

int findMin(int numbers[], int n);
int findMax(int numbers[], int n);
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
    sortWithIntervals(numbers, n);

    cout << "Before: ";
    printArray(numbers, n);
    sortWithIntervalsInPlace(numbers, n);

    return 0;
}

void sortWithIntervals(int numbers[], int n)
{
    int minVal = findMin(numbers, n);
    int maxVal = findMax(numbers, n);
    int difference = (maxVal - minVal) / (n - 1);
    cout << "Difference: " << difference << endl;

    int temp[n - 1];

    for (int i = 0; i < n; i++)
    {
        temp[(numbers[i] - minVal) / difference] = numbers[i];
    }

    cout << "After: ";
    printArray(temp, n);
}

void sortWithIntervalsInPlace(int numbers[], int n)
{
    int minVal = findMin(numbers, n);
    int maxVal = findMax(numbers, n);
    int difference = (maxVal - minVal) / (n - 1);
    cout << "Difference: " << difference << endl;

    for (int i = 0; i < n; i++)
    {
        numbers[i] = minVal + (difference * i);
    }

    cout << "After: ";
    printArray(numbers, n);
}

int findMin(int numbers[], int n)
{
    int minValue = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] < minValue)
        {
            minValue = numbers[i];
        }
    }

    return minValue;

}

int findMax(int numbers[], int n)
{
    int maxValue = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > maxValue)
        {
            maxValue = numbers[i];
        }
    }

    return maxValue;

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
