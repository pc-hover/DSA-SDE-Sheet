#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> ans;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            ans.push_back(nums[left]);
            left++;
        }
        else
        {
            ans.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        ans.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        ans.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = ans[i - low];
    }
}
int countPairs(vector<int> &nums, int low, int mid, int high)
{
    int right = mid + 1;
    int count = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2LL * nums[right])
        {
            right++;
        }
        count = count + right - (mid + 1);
    }
    return count;
}
int mergeSort(vector<int> &nums, int low, int high)
{
    int mid = (low + high) / 2;
    int count = 0;
    if (low >= high)
    {
        return count;
    }
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);

    return count;
}
int team(vector<int> &skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

// int ReversePairs(vector<int> &nums)
// {
//     int count = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if (nums[i] > nums[j] * 2)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
int main()
{
    vector<int> nums = {4, 1, 2, 3, 1};
    cout << "Reverse Inversions=" << team(nums, nums.size());

    return 0;
}
