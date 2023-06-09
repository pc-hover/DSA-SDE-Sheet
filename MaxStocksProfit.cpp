#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    // Optimal Approach
    // TC --> O(n)
    // SC -->O(1)
    int maxProfit(vector<int> &a)
    {
        int maxprofit = 0;
        int profit = 0;
        int minsofar = a[0];
        for (int i = 0; i < a.size(); i++)
        {
            if (minsofar > a[i])
            {
                minsofar = a[i];
            }
            profit = a[i] - minsofar;
            if (profit < 0)
            {
                profit = 0;
            }
            if (profit > maxprofit)
            {
                maxprofit = profit;
            }
        }
        return maxprofit;
    }
};
int main()
{
    Solution s;
    vector<int> a = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit = " << s.maxProfit(a);
    return 0;
}