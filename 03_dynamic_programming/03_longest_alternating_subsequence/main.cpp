#include <iostream>

using namespace std;

int findLength(int arr[], int n);

int main()
{
	int n = 0;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << findLength(arr, n) << endl;

	return 0;
}

int findLength(int arr[], int n)
{
	int up[n];
	int down[n];

	for (int i = 0; i < n; i++)
	{
		up[i] = 1;
		down[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				up[i] = max(up[i], down[j] + 1);
			}
			else if (arr[i] < arr[j])
			{
				down[i] = max(down[i], up[j] + 1);
			}
		}
	}

	int m = 0;

	for (int i = 0; i < n; i++)
	{
		m = max(m, max(up[i], down[i]));
	}

	return m;
}
