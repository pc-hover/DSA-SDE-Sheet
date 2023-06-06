#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void display(vector<int> a)
    {
        cout << "Colors in order :" << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << " " << a[i];
        }
    }
    void Sortcolors(vector<int> &a)
    {
        int n = a.size();
        int mid = 0;
        int low = 0;
        int high = n - 1;
        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(a[low], a[mid]);
                mid++;
                low++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else if (a[mid] == 2)
            {
                swap(a[mid], a[high]);
                high--;
            }
        }
        display(a);
    }
};
int main()
{
    // 0-->red
    // 0-->white
    // 0-->blue
    vector<int> x = {2, 0, 1};
    Solution s;
    s.Sortcolors(x);
    return 0;
}