class Solution {
public:
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        int components = n;
        for (auto& conn : connections) {
            int rootA = find(conn[0]);
            int rootB = find(conn[1]);
            if (rootA != rootB) {
                parent[rootA] = rootB;
                components--;
            }
        }
        return components - 1;
    }
};

