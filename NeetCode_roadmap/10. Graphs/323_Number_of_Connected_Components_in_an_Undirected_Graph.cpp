class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        DisjointSet ds(n);
        int components = n;

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                ds.unionBySize(u, v);
                components--;
            }
        }

        return components;
    }
};