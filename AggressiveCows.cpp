#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int cows, int min)
{
    int cowsPlaced = 1;
    int lastCow = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - lastCow >= min)
        {
            lastCow = arr[i];
            cowsPlaced += 1;
        }
    }
    if (cowsPlaced >= cows)
    {
        return true;
    }
    return false;
}
int MaxMinDistance(vector<int> &arr, int cows)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr[n - 1] - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPossible(arr, cows, mid))
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return high;
}
int main()
{
    vector<int> arr = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    cout << "Maximum of minimum distances between the cows is " << MaxMinDistance(arr, cows);

    return 0;
}