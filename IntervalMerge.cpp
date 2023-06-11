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
            cout << "   ";
        }
        cout << endl;
    }
    vector<vector<int>> merge(vector<vector<int>> &a)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int start = a[i][0];
            int end = a[i][1];
            if (!ans.empty() && end <= ans[ans.size() - 1][1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (end >= a[j][0])
                {
                    end = max(a[j][1], end);
                }
                else
                {
                    break;
                }
            }
            ans.push_back({start, end});
        }

        return ans;
    }
};
int main()
{
    Solution s;

    vector<vector<int>> a = {{1, 4}, {0, 0}};
    vector<vector<int>> ans = s.merge(a);
    s.display(ans);
}
