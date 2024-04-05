#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

void printArray(int numbers[], int n);
void linearSort(int numbers[], int n);

int main()
{
    int n = 0;
    cin >> n;

    int numbers[n] = {0};

    for (int i = 0; i < n; i++)
    {
        numbers[i] = i + 1;
    }

    shuffle(numbers, numbers + n, mt19937{random_device{}()});

    cout << "Before: ";
    printArray(numbers, n);

    linearSort(numbers, n);

    cout << "After: ";
    printArray(numbers, n);

    return 0;
}

void linearSort(int numbers[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        numbers[i - 1] = i;
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
