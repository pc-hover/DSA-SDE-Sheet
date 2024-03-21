#include <bits/stdc++.h>
using namespace std;

/*
1.Connect u and v unionByRank
2.Tells whether u and v belongs to same component inside the graph
*/
class DisjointSet
{

    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int findParent(int node) // using recursion
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int Ultu = findParent(u);
        int Ultv = findParent(v);

        if (Ultu == Ultv)
        {
            return;
        }
        if (rank[Ultu] == rank[Ultv])
        {
            parent[v] = Ultu;
        }
        else if (rank[Ultu] > rank[Ultv])
        {
            parent[Ultv] = Ultu;
        }
        else
        {
            parent[u] = Ultv;
            rank[Ultv]++;
        }
    }
};