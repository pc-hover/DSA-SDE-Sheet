#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void display(vector<int> x)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout << " " << x[i];
        }
    }
    void NextPermutation(vector<int> &a)
    {
        int n = a.size();
        int temp = -1;

        // step 1
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                temp = i;
                break;
            }
        }
        if (temp == -1)
        {
            reverse(a.begin(), a.end());
            display(a);
            exit(0);
        }

        // step 2
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > a[temp])
            {
                // step 3
                swap(a[i], a[temp]);
                break;
            }
        }

        // step 4
        reverse(a.begin() + temp + 1, a.end());
        display(a);
    }
};
int main()
{
    Solution s;
    vector<int> x = {3, 2, 1};
    s.display(x);
    cout << endl;
    s.NextPermutation(x);

    return 0;
}