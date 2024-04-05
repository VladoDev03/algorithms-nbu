#include <iostream>

using namespace std;

int findTotal(int n);

int main()
{
    int n = 0;
    cin >> n;

    cout << findTotal(n) << endl;

    return 0;
}

int findTotal(int n)
{
    long long int total = 1;

    for(int i = 1; i <= n; i++)
    {
		total = (total * (10 + i - 1)) / i;
    }

    return total;
}
