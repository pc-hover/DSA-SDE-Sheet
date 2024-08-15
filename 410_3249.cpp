#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<list<int>> adj;
    int dfs(int i,
            int par, vector<int> &size)
    {

        int count = 1;
        for (auto it : adj[i])
        {
            if (it != par)
            {

                count = count + dfs(it, i, size);
            }
        }
        size[i] = count;
        return count;
    }
    int countGoodNodes(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        adj.resize(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        vector<int> size(n, 0);
        dfs(0, -1, size);

        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            int prev = -1;
            for (auto it : adj[i])
            {
                if (size[it] < size[i])
                {
                    if (prev == -1)
                    {
                        prev = size[it];
                    } // firsttime
                    else if (prev != size[it])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                ans++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution solution;

    // Example graph represented as edges
    // Example: edges = [[0, 1], [1, 2], [1, 3], [3, 4]]
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {1, 3},
        {3, 4}};

    int result = solution.countGoodNodes(edges);

    cout << "Number of good nodes: " << result << endl;

    return 0;
}