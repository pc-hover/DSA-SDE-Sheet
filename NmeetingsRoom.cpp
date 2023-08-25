#include <bits/stdc++.h>
using namespace std;

vector<int> nMeetingsRoom(vector<int> &start, vector<int> &end)
{

    vector<int> temp;
    vector<int> ans;
    for (int i = 0; i < start.size(); i++)
    {
        if (i == 0)
        {
            temp.push_back(end[i]);
            ans.push_back(i + 1);
        }
        else if (start[i] >= temp[temp.size() - 1])
        {
            temp.push_back(end[i]);
            ans.push_back(i + 1);
        }
    }
    return ans;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> ends = {2, 4, 5, 7, 9, 9};
    vector<int> ans = nMeetingsRoom(start, ends);
    for (auto it : ans)
    {
        cout << " " << it;
    }

    return 0;
}