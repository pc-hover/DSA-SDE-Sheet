// Trapping Rain Water
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        int right_max = 0;
        int left_max = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= left_max)
                    left_max = height[left];

                else
                    res += left_max - height[left];

                left++;
            }
            else
            {
                if (height[right] >= right_max)
                    right_max = height[right];

                else
                    res += right_max - height[right];

                right--;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << "WATER TRAPPED IS = " << s.trap(height);
    return 0;
}