#include <iostream>

using namespace std;

void countingSort(int a[], int b[], int n);
void printArray(int numbers[], int n);

int main()
{
    int n = 0;
    cin >> n;

    int a[n], b[n];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    countingSort(a, b, n);

    cout << "Before: ";
    printArray(a, n);

    cout << "After: ";
    printArray(b, n);

    cout << sizeof(b) / sizeof(b[0]) << endl;

    return 0;
}

void countingSort(int a[], int b[], int n)
{
    int k = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > k)
        {
            k = a[i];
        }
    }

    int c[k];

    for (int i = 0; i <= k; i++)
    {
        c[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        c[a[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        c[i] += c[i - 1];
    }

    for (int i = n; i >= 1; i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
}

void printArray(int numbers[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << numbers[i];

        if (i < n)
        {
            cout << " ";
        }
    }

    cout << endl;
}
