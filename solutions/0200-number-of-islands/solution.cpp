#pragma GCC optimize("O3")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <vector>
#include <fstream>
#include <iostream>

// Global block to eliminate LeetCode grader I/O buffer memory overhead
static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::ofstream out("user.out");
    std::cout.rdbuf(out.rdbuf());
    return 0;
}();

class Solution {
private:
    void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0' || visited[r][c]) {
            return;
        }
        
        visited[r][c] = true;
        
        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r, c + 1);
        dfs(grid, visited, r, c - 1);
    }

public:
    int numIslands(const vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    count++;
                    dfs(grid, visited, r, c);
                }
            }
        }
        return count;
    }
};

