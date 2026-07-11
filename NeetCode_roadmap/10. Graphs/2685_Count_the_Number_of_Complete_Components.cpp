class DSU
{
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int u_par = findPar(u);
        int v_par = findPar(v);

        if (u_par == v_par)
        {
            return;
        }
        if (size[u_par] < size[v_par])
        {
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
        else
        {
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        }
    }
};

class Solution
{
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        DSU ds(n);
        int complete_comp = n;

        for (auto &it : edges)
        {
            ds.unionBySize(it[0], it[1]);
        }

        unordered_map<int, int> componentSize;
        unordered_map<int, int> componentEdges;

        // Count nodes in each component
        for (int i = 0; i < n; i++)
        {
            int par = ds.findPar(i);
            componentSize[par]++;
        }

        // Count edges in each component
        for (auto &it : edges)
        {
            int par = ds.findPar(it[0]);
            componentEdges[par]++;
        }

        int ans = 0;

        // Check complete components
        for (auto &[par, nodes] : componentSize)
        {
            int edgeCount = componentEdges[par];

            if (edgeCount == (nodes * (nodes - 1)) / 2)
            {
                ans++;
            }
        }

        return ans;
    }
};