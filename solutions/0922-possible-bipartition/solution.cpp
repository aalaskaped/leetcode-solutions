class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (const auto& d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }

        vector<int> colors(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            if (colors[i] == 0) {
                queue<int> q;
                q.push(i);
                colors[i] = 1;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int neighbor : graph[u]) {
                        if (colors[neighbor] == 0) {
                            colors[neighbor] = -colors[u];
                            q.push(neighbor);
                        } else if (colors[neighbor] == colors[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


