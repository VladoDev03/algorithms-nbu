#include <iostream>
#include <vector>

using namespace std;

int recurZigZag(vector<vector<int>> matrix, int row, int col, int n, int** dp);
void printMatrix(vector<vector<int>> matrix);

int main()
{
    int n = 0;
    cin >> n;

    vector<vector<int>> matrix;
    int item = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;

        for (int j = 0; j < n; j++)
        {
            cin >> item;
            row.push_back(item);
        }

        matrix.push_back(row);
    }

    int** dp = (int**)(malloc(sizeof(int*) * n));

    for (int i = 0; i < n; i++)
    {
        dp[i] = (int*)(malloc(sizeof(int) * n));

        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currentSum = recurZigZag(matrix, 0, i, n, dp);

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }

    printMatrix(matrix);

    cout << maxSum << endl;

    return 0;
}

int recurZigZag(vector<vector<int>> matrix, int row, int col, int n, int** dp)
{
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    if (row == n - 1)
    {
        dp[row][col] = matrix[row][col];

        return matrix[row][col];
    }

    int maxVal = INT_MIN;

    for (int currCol = 0; currCol < n; currCol++)
    {
        if (currCol != col)
        {
            int recurRes = recurZigZag(matrix, row + 1, currCol, n, dp);

            if (maxVal < recurRes)
            {
                maxVal = recurRes;
            }
        }
    }

    dp[row][col] = max(dp[row][col], matrix[row][col] + maxVal);

    return dp[row][col];
}

void printMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];

            if (j < n - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}
