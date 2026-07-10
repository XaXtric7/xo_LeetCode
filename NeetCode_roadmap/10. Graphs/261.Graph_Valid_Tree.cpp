class Solution
{
private:
    bool dfs(int node, int parent, unordered_set<int> &visit,
             vector<vector<int>> &adj)
    {
        if (visit.count(node))
        {
            return false;
        }

        visit.insert(node);
        for (int nei : adj[node])
        {
            if (nei == parent)
            {
                continue;
            }
            if (!dfs(nei, node, visit, adj))
            {
                return false;
            }
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        if (edges.size() > n - 1)
        {
            return false;
        }

        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> visit;

        if (!dfs(0, -1, visit, adj))
        {
            return false;
        }

        return visit.size() == n;
    }
};
