#include <iostream>

using namespace std;

int efficientAlgorithm(int lines[], int n);
int bruteForce(int lines[], int n);

int main()
{
    int n = 0;
    cin >> n;
    int lines[n] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> lines[i];
    }

    cout << "Efficien Algorithm: " << efficientAlgorithm(lines, n) << endl;
    cout << "Brute Force Algorithm: " << bruteForce(lines, n) << endl;

    return 0;
}

int efficientAlgorithm(int lines[], int n)
{
    int left[n], right[n];

    left[0] = lines[0];
    right[n - 1] = lines[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], lines[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], lines[i]);
    }

    int sum = 0;

    for (int i = 1; i < n - 1; i++)
    {
        sum += (min(left[i], right[i]) - lines[i]);
    }

    return sum;
}

int bruteForce(int lines[], int n)
{
    int sum = 0;
    int left = 0;
    int right = 0;

    for (int i = 0; i < n - 1; i++)
    {
        left = lines[i];
        right = lines[i];

        for (int j = 0; j < i; j++)
        {
            left = max(lines[j], left);
        }

        for (int j = i + 1; j < n; j++)
        {
            right = max(right, lines[j]);
        }

        sum = sum + (min(left, right) - lines[i]);
    }

    return sum;
}
