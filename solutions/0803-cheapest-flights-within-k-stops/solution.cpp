class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> tmp = dist;
            for (const auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] != 1e9 && dist[u] + w < tmp[v]) {
                    tmp[v] = dist[u] + w;
                }
            }
            dist = tmp;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

