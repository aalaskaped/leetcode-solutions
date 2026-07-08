class Solution {
private:
    bool bfsHasPath(vector<vector<int>>& adj_list, int src, int dst,
                    vector<bool>& visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dst) {
                return true;
            }

            for (int neighbor : adj_list[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination)
            return true;

        vector<vector<int>> adj_list(n);
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        return bfsHasPath(adj_list, source, destination, visited);
    }
};

