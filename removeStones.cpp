#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1); //{0,1,2...}
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node) // find ultimate parent
    {
        if (node == parent[node])
        {
            return node;
        }
        // here we are also performing path compression.
        return parent[node] = findUPar(parent[node]); // here we are simply asigning whole branch parent[] as node
    }
    void unionByRank(int u, int v)
    {
        int ulP_u = findUPar(u);
        int ulP_v = findUPar(v);

        if (ulP_u == ulP_v)
            return;
        if (rank[ulP_u] < rank[ulP_v])
        {
            parent[ulP_u] = ulP_v;
        }
        else if (rank[ulP_v] < rank[ulP_u])
        {
            parent[ulP_v] = ulP_u;
        }
        else
        {
            parent[ulP_v] = ulP_u;
            rank[ulP_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulP_u = findUPar(u);
        int ulP_v = findUPar(v);

        if (ulP_u == ulP_v)
            return;

        if (size[ulP_u] < size[ulP_v])
        {
            parent[ulP_u] = ulP_v;
        }
        else if (size[ulP_v] <= size[ulP_u])
        {
            parent[ulP_v] = ulP_u;
        }
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {

        // create the matrix
        int max_x = 0, max_y = 0;
        for (auto it : stones)
        {
            max_x = max(max_x, it[0]);
            max_y = max(max_y, it[1]);
        }
        int rows = max_x + 1;
        int cols = max_y + 1;

        DisjointSet ds(rows + cols + 1);

        for (auto it : stones)
        {
            int rowNode = it[0];
            int colNode = it[1] + rows;

            ds.unionBySize(rowNode, colNode);
            stoneNode[rowNode]
        }
    }
};

int main()
{
    Solution s;
    cout << "Hello, World!" << endl;
    return 0;
}