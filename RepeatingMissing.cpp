#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Optimal Approach 2*
    // TC --> O(n)
    // SC --> O(1)
    vector<int> ReapeatingMissing(vector<int> nums1)
    {
        int n = nums1.size();
        int sum1 = 0;
        int sum2 = 0;
        int sumn = n * (n + 1) / 2;
        int sum2n = (n * (n + 1) * ((2 * n) + 1)) / 6;

        for (int i = 0; i < n; i++)
        {
            sum1 = sum1 + nums1[i];
            sum2 = sum2 + nums1[i] * nums1[i];
        }
        int A = sum1 - sumn;
        int B = sum2 - sum2n;
        int r = ((B / A) + A) / 2;
        int m = r - A;
        return {r, m};
    }
};

int main()
{
    vector<int> nums1 = {3, 1, 2, 5, 4, 6, 7, 5};
    Solution s;
    vector<int> ans = s.ReapeatingMissing(nums1);
    cout << ans[0] << " , " << ans[1];
    return 0;
}