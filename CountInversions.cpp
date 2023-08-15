#include <bits/stdc++.h>
using namespace std;
int mergeArray(vector<int> &arr, int low, int mid, int high)
{
    vector<int> ans;
    int count = 0;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            count = count + mid - left + 1;
            ans.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        ans.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        ans.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
    return count;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int mid = (low + high) / 2;
    int count = 0;

    if (low >= high)
    {
        return count;
    }

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += mergeArray(arr, low, mid, high);
    return count;
}
int main()
{
    vector<int> arr = {5, 4, 1, 2, 1};
    cout << "Total Inversions =" << mergeSort(arr, 0, arr.size() - 1);
    return 0;
}