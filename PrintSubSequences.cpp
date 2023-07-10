#include <bits/stdc++.h>
using namespace std;

void printF(int i, vector<int> &ds, int arr[], int n)
{
    if (i == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }

        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[i]);
    printF(i + 1, ds, arr, n);
    ds.pop_back();

    printF(i + 1, ds, arr, n);
}

int main()
{
    int arr[] = {5, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    printF(0, ds, arr, n);
    return 0;
}