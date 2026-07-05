class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : roads)
        {
            int city1 = it[0];
            int city2 = it[1];
            int w = it[2];

            adj[city1].push_back({city2, w});
            adj[city2].push_back({city1, w});
        }

        vector<int> visited(n + 1, 0);

        queue<int> q;
        q.push(1);
        visited[1] = 1;

        int minScore = INT_MAX;

        while (!q.empty())
        {
            int city1 = q.front();
            q.pop();

            for (auto it : adj[city1])
            {
                int city2 = it.first;
                int weight = it.second;

                minScore = min(minScore, weight);

                if (!visited[city2])
                {
                    visited[city2] = 1;
                    q.push(city2);
                }
            }
        }
        return minScore;
    }
};