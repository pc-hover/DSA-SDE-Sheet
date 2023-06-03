#include <iostream>
#include <vector>
using namespace std;
// Problem 1 --> Find element at position R,C
// Problem 2 --> Find row R elements
// Problem 3 --> Construct the Parscals Triangle of Given Number of Rows
class Solution
{
public:
    void SearchP(int rw, int col)
    {
        rw = rw - 1;
        col = col - 1;
        int res = 1;
        for (int i = 0; i < col; i++)
        {
            res = res * (rw - i);
            res = res / (i + 1);
        }
        cout << res;
    }
    void nthRow(int rw)
    {

        int ans = 1;
        cout << ans;
        for (int i = 1; i < rw; i++)
        {
            ans = ans * (rw - i);
            ans = ans / (i);
            cout << " " << ans;
        }
    }
    vector<int> GenerateRow(int row)
    {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for (int i = 1; i < row; i++)
        {
            ans = ans * (row - i);
            ans = ans / (i);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> PascalTriangle(int row)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= row; i++)
        {
            ans.push_back(GenerateRow(i));
        }
        return ans;
    }
};
int main()
{
    Solution s;

    s.nthRow(5);
    cout << endl;

    s.SearchP(6, 3);
    cout << endl;

    int n = 6;
    vector<vector<int>> pascalsTriangle = s.PascalTriangle(n);
    for (auto it : pascalsTriangle)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}