class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto& req : prerequisites) {
            adj[req[1]].push_back(req[0]);
            indegree[req[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo_order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);
            for (int neighbor : adj[u]) {
                if (--indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return topo_order.size() == numCourses ? topo_order : vector<int>();
    }
};

