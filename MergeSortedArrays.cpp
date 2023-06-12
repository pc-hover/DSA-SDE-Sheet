#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
private:
    void display(vector<int> arr1, vector<int> arr2)
    {
        int i = 0;
        cout << "nums1[] = ";
        while (i < arr1.size())
        {
            cout << " " << arr1[i];
            i++;
        }
        cout << endl;
        i = 0;
        cout << "nums2[] = ";
        while (i < arr2.size())
        {
            cout << " " << arr2[i];
            i++;
        }
    }

private:
    void swapping(vector<int> &nums1, vector<int> &nums2, int lt, int rt)
    {
        if (nums1[lt] > nums2[rt])
        {
            swap(nums1[lt], nums2[rt]);
        }
    }

public:
    void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
    {
        int len = m + n;
        int gap = (len / 2) + (len % 2);
        while (gap > 0)
        {

            int left = 0;
            int right = left + gap;
            while (right < len)
            {
                // right is in nums2 & left is in nums1
                if (left < n && right >= n)
                {
                    swapping(nums1, nums2, left, right - n);
                }
                // both right & left in nums2
                else if (left >= n)
                {
                    swapping(nums2, nums2, left - n, right - n);
                }
                // both right & left in nums1
                else
                {
                    swapping(nums1, nums1, left, right);
                }
                left++;
                right++;
            }

            if (gap == 1)
            {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
        display(nums1, nums2);
    }
};
int main()
{

    vector<int> nums1 = {1, 4, 8, 10};
    vector<int> nums2 = {2, 3, 9};
    Solution s;
    s.merge(nums1, nums1.size(), nums2, nums2.size());
}