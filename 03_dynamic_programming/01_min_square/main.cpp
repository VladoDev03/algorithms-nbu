#include <iostream>
#include <vector>

using namespace std;

int minSquare(int n);

int main()
{
    int n = 0;
    cin >> n;

    cout << "Minimum number of squares needed: " << minSquare(n) << endl;

    return 0;
}

int minSquare(int n)
{
    int dp[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = i;
    }

    dp[0] = 0;

    vector<int> a;

    for (int i = 1; ; i++)
    {
        if (i * i <= n)
        {
            a.push_back(i * i);
        }
        else
        {
            break;
        }
    }

    int m = a.size();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i >= a[j] && dp[i - a[j]] + 1 < dp[i])
            {
                dp[i] = dp[i - a[j]] + 1;
            }
        }
    }

    return dp[n];
}
