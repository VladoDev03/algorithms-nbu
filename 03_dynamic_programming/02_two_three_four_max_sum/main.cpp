#include <iostream>
#include <vector>

using namespace std;

int findMaxRecursive(int n);
int findMaxIterative(int n);

int arr[100001];

int main() {
	int n = 0;
	cin >> n;

	cout << "Recursive: " << findMaxRecursive(n) << endl;
	cout << "Iterative: " << findMaxIterative(n) << endl;

    return 0;
}

int findMaxRecursive(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int p = findMaxRecursive(n / 2) + findMaxRecursive(n / 3) + findMaxRecursive(n / 4);

    return max(n, p);
}

int findMaxIterative(int n)
{
	int arr[n + 1];
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int p = arr[i / 4] + arr[i / 3] + arr[i / 2];
		arr[i] = i > p ? i : p;
	}

	return arr[n];
}
