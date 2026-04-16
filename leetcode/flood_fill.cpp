#include <iostream>
#include <vector>

// Similar to Leetcode #733

// O(ROWS * COLS) time.
// O(ROWS * COLS) recursion stack, O(1) auxiliary space.
std::vector<std::vector<int>> image = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1}
};

const int ROWS = image.size();
const int COLS = image[0].size();

void dfs(int i, int j, int initialColor, int newColor) {

    if (i < 0 || j < 0 || i >= ROWS || j >= COLS || image[i][j] != initialColor) {
        return;
    }
    
    // If initialColor == newColor, it would keep calling DFS on neighbors which would DFS this again infinitely.
    // We can better place it in main() to remove redundant calls.
    // if (initialColor == newColor) return;

    image[i][j] = newColor;

    dfs(i, j+1, initialColor, newColor);
    dfs(i, j-1, initialColor, newColor);
    dfs(i+1, j, initialColor, newColor);
    dfs(i-1, j, initialColor, newColor);
}

int main() {
    int sr = 1, sc = 1, newColor = 1;

    if (image[sr][sc] != newColor) {
        dfs(sr, sc, image[sr][sc], newColor);
    }
    
    for (const std::vector<int>& row : image) {
        for (int pixel : row) {
            std::cout << pixel << " ";
        }
        std::cout << "\n";
    }
    return 0;
}