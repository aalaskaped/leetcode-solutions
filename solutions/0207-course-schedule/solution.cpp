class Solution {
private:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1) return true;
        if (visited[node] == 2) return false;

        visited[node] = 1;
        for (int neighbor : adj[node]) {
            if (hasCycle(neighbor, adj, visited)) return true;
        }
        visited[node] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && hasCycle(i, adj, visited)) return false;
        }
        return true;
    }
};

