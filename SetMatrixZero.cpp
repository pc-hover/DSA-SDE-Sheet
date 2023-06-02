#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // Optimal Approach
    vector<vector<int>> setZeroes(vector<vector<int>> &matrix, int n, int m)
    {
        int col0 = 1;
        // Mark 0s
        // matrix[..][0] and //marking matrix[0][..]
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                    {
                        matrix[0][j] = 0;
                    }
                    else
                        col0 = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // mark Row and col elements
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
        return matrix;
    }
    // Better Approach
    //  vector<vector<int>> setZeroes(vector<vector<int>> &matrix , int n ,int m)
    //  {
    //      int n = matrix.size();
    //      int m = matrix[0].size();
    //      int row[n] = {0};
    //      int col[m] = {0};
    //      for (int i = 0; i < n; i++)
    //      {
    //          for (int j = 0; j < m; j++)
    //          {
    //              if (matrix[i][j] == 0)
    //              {
    //                  row[i] = 1;
    //                  col[j] = 1;
    //              }
    //          }
    //      }
    //      for (int i = 0; i < n; i++)
    //      {
    //          for (int j = 0; j < m; j++)
    //          {
    //              if (row[i] || col[j])
    //              {
    //                  matrix[i][j] = 0;
    //              }
    //          }
    //      }
    //      return matrix;
    //  }
    void display(vector<vector<int>> array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = 0; j < array[0].size(); j++)
            {
                cout << array[i][j];
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> x = {{0, 1, 0, 9}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    s.display(x);
    int n = x.size();
    int m = x[0].size();
    vector<vector<int>> y = s.setZeroes(x, n, m);

    cout << endl;
    s.display(y);
    return 0;
}