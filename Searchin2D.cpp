#include <bits/stdc++.h>
using namespace std;
bool Searchin2D(vector<vector<int>> &nums, int target)
{
    int n = nums.size();
    int m = nums[0].size();
    int low = 0;
    int high = (n * m) - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // mid will be converted to 2D c0ordinates
        int row = mid / m;
        int col = mid % m;

        if (nums[row][col] == target)
            return true;
        else if (nums[row][col] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> nums = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};
    cout << Searchin2D(nums, 23);
    return 0;
}