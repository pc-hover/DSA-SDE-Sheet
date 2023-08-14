#include <bits/stdc++.h>
using namespace std;
void HighestLowest(int arr[], int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int low = INT_MAX;
    int lowele;
    int high = INT_MIN;
    int highele;
    for (const auto &it : mp)
    {
        if (it.second < low)
        {
            low = it.second;
            lowele = it.first;
        }
        if (it.second > high)
        {
            high = it.second;
            highele = it.first;
        }
    }
    cout << "Highest Element = " << highele;
    cout << "Lowest Element = " << lowele;
}
int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    HighestLowest(arr, n);
    return 0;
}