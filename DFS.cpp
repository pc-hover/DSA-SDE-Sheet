#include <bits/stdc++.h>
using namespace std;
void func(int node, vector<int> adj[], vector<int> &ans, bool visit[])
{
    ans.push_back(node);
    visit[node] = 1;
    for (auto it : adj[node])
    {
        if (!visit[it])
        {
            func(it, adj, ans, visit);
        }
    }
}
void dfsOfGraph(vector<int> adj[], int start)
{
    vector<int> ans;
    bool visit[start] = {false}; //??
    func(start, adj, ans, visit);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << " " << ans[i];
    }
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> adj[m + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    int start = 1;
    dfsOfGraph(adj, start);
}
// void DFS(vector<int> adj[], int start)
// {
//     stack<int> st;
//     size_t m = sizeof(adj) / sizeof(adj[0]);
//     bool visit[m] = {0};

//     st.push(start);
//     visit[start] = 1;
//     while (!st.empty())
//     {
//         int n = st.top();
//         cout << " " << n;
//         st.pop();
//         for (int i = 0; i < adj[n].size(); i++)
//         {
//             if (!visit[adj[n][i]])
//             {
//                 st.push(adj[n][i]);
//                 visit[adj[n][i]] = 1;
//             }
//         }
//     }
// }