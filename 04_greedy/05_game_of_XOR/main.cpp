#include <iostream>

using namespace std;

int gameOfXOR(int numbers[], int n);

int main()
{
    int n = 0;
    cin >> n;
    int numbers[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << gameOfXOR(numbers, n) << endl;

    return 0;
}

int gameOfXOR(int numbers[], int n)
{
    if (n % 2 == 0)
    {
        return 0;
    }

    int sum = numbers[0];

    for (int i = 2; i < n; i+=2)
    {
        sum = sum^numbers[i];
    }

    return sum;
}
