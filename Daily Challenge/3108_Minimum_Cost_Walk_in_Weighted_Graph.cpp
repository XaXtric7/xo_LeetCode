// Building DSU (Union-Find) → O(N log N)
// Processing queries → O(Q log N)
// Overall Complexity: O((N + Q) log N)

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> parent, minPathCost;

    int f_Root(int node)
    {
        if (parent[node] != node)
        {
            parent[node] = f_Root(parent[node]); // Path compression
        }
        return parent[node];
    }

    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        parent.resize(n);
        minPathCost.assign(n, -1);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &edge : edges)
        {
            int source = edge[0], target = edge[1], weight = edge[2];
            int sourceRoot = f_Root(source);
            int targetRoot = f_Root(target);

            if (minPathCost[sourceRoot] == -1)
                minPathCost[sourceRoot] = weight;
            else
                minPathCost[sourceRoot] &= weight;

            if (minPathCost[targetRoot] == -1)
                minPathCost[targetRoot] = weight;
            else
                minPathCost[targetRoot] &= weight;

            if (sourceRoot != targetRoot)
            {
                parent[sourceRoot] = targetRoot;
                minPathCost[targetRoot] &= minPathCost[sourceRoot];
            }
        }

        vector<int> result;
        for (auto &q : queries)
        {
            int start = q[0], end = q[1];

            if (start == end)
                result.push_back(0);
            else if (f_Root(start) != f_Root(end))
                result.push_back(-1);
            else
                result.push_back(minPathCost[f_Root(start)]);
        }

        return result;
    }
};