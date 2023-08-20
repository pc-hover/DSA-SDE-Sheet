#include <iostream>
#include <vector>
using namespace std;

int maxCount1(vector<int> &arr, int n)
{
    int maxcount = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count = count + 1;
            if (maxcount < count)
            {
                maxcount = count;
            }
        }
        else
        {
            count = 0;
        }
    }
    return maxcount;
}
int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    cout << "Maximum Count of One's : " << maxCount1(arr, arr.size());
    return 0;
}