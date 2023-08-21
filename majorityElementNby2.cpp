#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ele = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                ele = nums[i];
                count = 1;
            }
            else if (ele == nums[i])
                count++;

            else
                count--;
        }
        int count1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ele)
                count1++;
        }
        if (count1 > nums.size() / 2)
            return ele;

        return -1;
    }

    // TC-> O(n)
    // SC->O(n)
    //     int majorityElement(vector<int> &nums)
    //     {

    //         unordered_map<int, int> mp;
    //         int n = nums.size();
    //         int i = 0;
    //         while (i < n)
    //         {
    //             mp[nums[i]]++;
    //             i++;
    //         }
    //         int m = -1;
    //         for (auto it : mp)
    //         {
    //             if (it.second > n / 2)
    //             {
    //                 m = it.first;
    //                 break;
    //             }
    //         }
    //         return m;
    //     }
};
int main()
{
    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(nums);

    return 0;
}