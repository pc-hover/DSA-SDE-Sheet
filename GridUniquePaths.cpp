#include <bits/stdc++.h>
using namespace std;
// Most Optimal Approach USING COMBINATIONS
// TC-> O(M-1)
// SC-> O(1)
int GridUniquePaths(int m, int n)
{
    int x = m + n - 2;
    int y = m - 1;
    int res = 1;
    for (int i = 1; i <= y; i++)
    {
        res = res * (x - y + i) / i;
    }

    return (int)res;
}

// TC-> EXPONENTIAL
// SC-> EXPONENTIAL
int GridUniquePaths_recursion(int i, int j, int m, int n)
{
    if (i >= m || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    return GridUniquePaths_recursion(i + 1, j, m, n) + GridUniquePaths_recursion(i, j + 1, m, n);
}

// TC-> O(n*m)
// SC-> O(n*m)
int GridUniquePaths_dp(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    else
        return dp[i][j] = GridUniquePaths_dp(i + 1, j, m, n, dp) + GridUniquePaths_dp(i, j + 1, m, n, dp);
}
int main()
{
    int m = 3, n = 2;
    int totalCount = GridUniquePaths(2, 3);
    int totalCount_recursion = GridUniquePaths_recursion(0, 0, 2, 3);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int totalCount_dp = GridUniquePaths_dp(0, 0, 2, 3, dp);
    cout << "The total number of Unique Paths are " << totalCount << endl;
    cout << "The total number of Unique Paths are " << totalCount_recursion << endl;
    cout << "The total number of Unique Paths are " << totalCount_dp << endl;

    return 0;
}