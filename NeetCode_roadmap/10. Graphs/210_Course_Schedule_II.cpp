class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // 1. Build the dependency graph...
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        // 2. Queue courses that have no prerequisites...
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        // 3. Process the graph...
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            order.push_back(curr);

            for (int neighbor : adj[curr]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        }
        
        return {};
    }
};