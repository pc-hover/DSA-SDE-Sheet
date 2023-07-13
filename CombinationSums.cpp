#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findCombinations(int ind, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int target)
    {
        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        // Pick up
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]);
            findCombinations(ind, arr, ans, ds, target - arr[ind]);
            ds.pop_back();
        }
        // Not Pick
        findCombinations(ind + 1, arr, ans, ds, target);
    }

public:
    void CombinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, ans, ds, target); // Here 0 is the initial index
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << " " << ans[i][j];
            }
            cout << endl;
        }
    }
};
int main()
{
    Solution s;
    int target = 7;
    vector<int> candidates = {2, 3, 6, 7};
    s.CombinationSum(candidates, target);
    return 0;
}