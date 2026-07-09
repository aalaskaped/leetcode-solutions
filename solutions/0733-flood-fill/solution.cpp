#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
private:
    void dfs(vector<vector<int>>& image, int r, int c, int originalColor,
             int color) {

        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ||
            image[r][c] != originalColor) {
            return;
        }

        image[r][c] = color;

        dfs(image, r - 1, c, originalColor, color);
        dfs(image, r + 1, c, originalColor, color);
        dfs(image, r, c - 1, originalColor, color);
        dfs(image, r, c + 1, originalColor, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int originalColor = image[sr][sc];

        if (originalColor != color) {
            dfs(image, sr, sc, originalColor, color);
        }

        return image;
    }
};

