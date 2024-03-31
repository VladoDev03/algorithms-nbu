#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fill;
using std::max;

// functions declarations
string reconstruct(string text1, string text2, int **dp, int n, int m);
void printMatrix(int **dp, int n, int m);
int lcs(string text1, string text2);

int main()
{
    string text1 = "ace";
    string text2 = "abcde";

    cout << lcs(text1, text2) << endl;

    return 0;
}

/*
    Function that reconstructs the LCS.
    Takes five arguments:
        text1 -> first sequence
        text2 -> second sequence
        dp -> two dimensional array with the results of the dynamic programming algorithm
        n -> first sequence length
        m -> second sequence length
*/
string reconstruct(string text1, string text2, int **dp, int n, int m)
{
    int i = 0, j = 0;

    string result = "";

    while (i < m && j < n)
    {
        if (text1[i] == text2[j])
        {
            // Continuing with the sequences
            result += text1[i];
            ++i;
            ++j;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
        {
            // getting the the cell bellow the current one
            ++i;
        }
        else
        {
            // getting the the cell on the right
            ++j;
        }
    }

    return result;
}

void printMatrix(int **dp, int n, int m)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }
}

/*
    Function that finds the length of the LCS.
    Takes two arguments:
        text1 -> first sequence
        text2 -> second sequence
*/
int lcs(string text1, string text2)
{
    int n = text2.size();
    int m = text1.size();

    int **dp = new int*[m + 1];

    // initializing matrix
    for (int i = 0; i <= m; ++i) {
        dp[i] = new int[n + 1];
        fill(dp[i], dp[i] + n + 1, 0);
    }


    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            // Choosing which value to increase
            if (text1[i] == text2[j])
            {
                // Adding one to the bottom right cell
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                // Picking the bigger value between the bottom and the right cell
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    printMatrix(dp, n, m);

    int result = dp[0][0];

    cout << reconstruct(text1, text2, dp, n, m) << endl;

    // Cleaning up memory
    for (int i = 0; i <= m; ++i) {
        delete[]dp[i];
    }

    delete[]dp;

    return result;
}
