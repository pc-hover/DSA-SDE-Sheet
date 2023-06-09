#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void display(vector<vector<int>> x)
    {
        int n = x.size();
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < x[0].size(); j++)
            {
                cout << " " << x[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    void rotate(vector<vector<int>> &a)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(a[i][j], a[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            reverse(a[i].begin(), a[i].end());
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> a = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    s.display(a);
    s.rotate(a);
    s.display(a);
    return 0;
}