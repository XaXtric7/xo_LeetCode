// Time complexity -> ≈ O(V + E)
// Space complexity -> 	O(V + E)

class Solution
{
public:
    unordered_map<int, vector<int>> graph;

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited.find(i) == visited.end())
            {
                unordered_set<int> component;
                dfs(i, component, visited);
                if (isCompleteComponent(component))
                    count++;
            }
        }
        return count;
    }

    void dfs(int node, unordered_set<int> &component, unordered_set<int> &visited)
    {
        component.insert(node);
        visited.insert(node);
        for (int neighbor : graph[node])
        {
            if (visited.find(neighbor) == visited.end())
            {
                dfs(neighbor, component, visited);
            }
        }
    }

    bool isCompleteComponent(unordered_set<int> &component)
    {
        for (int node : component)
        {
            if (graph[node].size() != component.size() - 1)
            {
                return false;
            }
        }
        return true;
    }
};