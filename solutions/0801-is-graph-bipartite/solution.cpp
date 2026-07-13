class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        std::vector<int> color(n, -1); // -1: no color, 0: color A, 1: color B

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                std::queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : graph[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) return false;
                    }
                }
            }
        }
        return true;
    }
};

