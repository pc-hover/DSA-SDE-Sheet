// Solved this problem using CycleDetection method

#include <bits/stdc++.h>
using namespace std;
class Solution
{

private:
    bool dfs(int node, vector<int> &visit, vector<int> &pathVisit, vector<vector<int>> &graph, vector<int> &checkState)
    {

        visit[node] = 1;
        pathVisit[node] = 1;
        checkState[node] = 0; //??

        // check for all adjacent nodes
        for (auto it : graph[node])
        {
            // Not visited
            if (!visit[it])

            {
                if (dfs(it, visit, pathVisit, graph, checkState) == true)
                {
                    checkState[it] = 0;
                    return true;
                }
            }
            // Visited + Same path
            // Cycle deletected we will not change their pathVisit to 0
            else if (pathVisit[it])
            {
                checkState[it] = 0;
                return true;
            }
        }

        checkState[node] = 1; // Safe node
        pathVisit[node] = 0;

        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> visit(n, 0);
        vector<int> pathVisit(n, 0);
        vector<int> safeNodes;
        vector<int> checkState(n, 0);

        // for components of graphs

        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                dfs(i, visit, pathVisit, graph, checkState);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (checkState[i])
            {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}};
    ;
    vector<int> ans = s.eventualSafeNodes(graph);
    for (auto it : ans)
    {
        cout << " " << it;
    }
    cout << endl;
    return 0;
}