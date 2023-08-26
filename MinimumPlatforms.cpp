#include <iostream>
#include <algorithm>
using namespace std;

int minimumPlatforms(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0;
    int platform = 1;
    int count = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            i++;
            platform++;
        }
        else
        {
            platform--;
            j++;
        }
        if (platform > count)
            count = platform;
    }
    return count;
}
int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    cout << minimumPlatforms(arr, dep, 6);
    return 0;
}