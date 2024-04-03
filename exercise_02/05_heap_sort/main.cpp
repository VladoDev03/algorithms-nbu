#include <iostream>

using namespace std;

void heapSort(int numbers[], int n);
void heapify(int numbers[], int n, int i);
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

    heapSort(numbers, n);

    printArray(numbers, n);

    return 0;
}

void heapSort(int numbers[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(numbers, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(numbers[0], numbers[i]);
        heapify(numbers, i, 0);
    }
}

void heapify(int numbers[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && numbers[l] > numbers[largest])
    {
        largest = l;
    }

    if (r < n && numbers[r] > numbers[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(numbers[i], numbers[largest]);
        heapify(numbers, n, largest);
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
