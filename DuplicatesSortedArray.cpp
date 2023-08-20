#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2, 2, 2, 3, 3};
    cout << s.removeDuplicates(nums);
    cout << endl;
    cout << s.removeElement(nums, 1);

    return 0;
}