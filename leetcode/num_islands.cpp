#include <iostream>
#include <vector>

// Similar to Leetcode #200

// O(ROWS * COLS) time.
// O(ROWS * COLS) recursion stack, O(1) auxiliary space.
std::vector<std::vector<int>> board = {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1}
};

const int ROWS = board.size();
const int COLS = board[0].size();

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= ROWS || j >= COLS || board[i][j] == 0) {
        return;
    }

    board[i][j] = 0;
    
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main() {
    int total {};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                dfs(i, j);
                total++;
            }
        }    
    }
    
    std::cout << total;
}