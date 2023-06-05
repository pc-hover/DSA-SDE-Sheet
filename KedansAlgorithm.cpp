#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarray(vector<int> &a)
    {
        long long n = a.size();
        long long cursum = 0;
        long long maxsum = LONG_LONG_MIN; // header used is <climits>
        for (int i = 0; i < n; i++)
        {
            cursum = cursum + a[i];
            if (cursum > maxsum)
            {
                maxsum = cursum;
            }
            if (cursum < 0)
            {
                cursum = 0;
            }
        }
        return maxsum;
    }
};
int main()
{
    Solution s;
    vector<int> x = {-2};
    cout << "Maximum sum of sub array is = " << s.maxSubarray(x);
    return 0;
}