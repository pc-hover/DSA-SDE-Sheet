#include <bits/stdc++.h>
using namespace std;
// MATRIX
//  int main()
//  {
//      int n, m;
//      cin >> n >> m;
//      int adj[n + 1][m + 1] = {0};
//      for (int i = 0; i < n; i++)
//      {
//          int u, v;
//          cin >> u >> v;
//          adj[u][v] = 1;
//          adj[v][u] = 1;
//      }
//      for (auto &it : adj)

//     {
//         for (auto it2 : it)
//         {
//             cout << " " << it2;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// ADJACENCY LIST
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1]; // where each element of the array is a vector of integers (vector<int>).
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (auto &it : adj)

    {
        for (auto it2 : it)
        {
            cout << " " << it2;
        }
        cout << endl;
    }
    return 0;
}