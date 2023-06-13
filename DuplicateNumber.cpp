#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Naive Approach
    // TC--> O(nlogn)
    // SC -->O(1)

    //  void DuplicateNumber(vector<int> a)
    //  {
    //      int n = a.size();
    //      sort(a.begin(), a.end());
    //      for (int i = 1; i < n; i++)
    //      {
    //          if (a[i] == a[i + 1])
    //          {
    //              cout << "Duplicate Number is " << a[i];
    //              break;
    //          }
    //      }
    //  }

    // Optimal Approach - 1
    //  TC-->O(n)
    //  SC-->O(n)

    //  int DuplicateNumber(vector<int> arr)
    //  {
    //      int n = arr.size();
    //      int freq[n + 1] = {0};//or  vector<int> freq(n + 1, 0);
    //      for (int i = 0; i < n; i++)
    //      {
    //          if (freq[arr[i]] == 0)
    //          {
    //              freq[arr[i]] = 1 + freq[arr[i]];
    //          }
    //          else
    //              return arr[i];
    //      }
    //      return 0;
    //  }

    // Optimal Approach - 2
    //  TC-->O(n)
    //  SC-->O(1)
    // Floyd's Tortoise and Hare algorithm
    int DuplicateNumber(vector<int> arr)
    {
        int fast = arr[0];
        int slow = arr[0];
        do
        {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        fast = arr[0];
        while (fast != slow)
        {
            fast = arr[fast];
            slow = arr[slow];
        }
        return fast;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {3, 5, 4, 1, 2, 3};
    cout << "Duplicate Number is = " << s.DuplicateNumber(nums1);
    return 0;
}