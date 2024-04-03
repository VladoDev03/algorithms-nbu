#include <iostream>
#include <vector>

using namespace std;

int maxOfThree(int a, int b, int c);
int lcsThree(string s1, string s2, string s3, int m, int n, int o);

int main()
{
    int t, m, n, o;
    cout << "Enter string1 length: ";
    cin >> m;
    cout << "Enter string2 length: ";
    cin >> n;
    cout << "Enter string3 length: ";
    cin >> o;

    string s1, s2, s3;
    cout << "Enter string1: ";
    cin >> s1;
    cout << "Enter string2: ";
    cin >> s2;
    cout << "Enter string3: ";
    cin >> s3;

    cout << "The length of LCS of the three strings is :" << lcsThree(s1, s2, s3, m, n, o) << endl;

    return 0;
}

int maxOfThree(int a, int b, int c)
{

    if (a > b && a > c)
    {
        return a;
    }
    if (b > c)
    {
        return b;
    }

    return c;
}

int lcsThree(string s1, string s2, string s3, int m, int n, int o)
{

    int dp[m + 1][n + 1][o + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= o; j++)
        {
            dp[0][i][j] = 0;
        }
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= o; j++)
        {
            dp[i][0][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= o; k++)
            {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else
                {
                    dp[i][j][k] = maxOfThree(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
                }
            }
        }
    }

    return dp[m][n][o];
}
