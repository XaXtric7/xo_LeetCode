class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Using Kahn's Algorithm (BFS + Topo Sort)...

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // creation of the adj list...
        for (auto &it : prerequisites)
        {
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all courses with no prerequisites
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        int complete = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            complete++;

            for (int neighbor : adj[curr])
            {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        return complete == numCourses;
    }
};