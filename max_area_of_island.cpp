#include <iostream>
#include <vector>

std::vector<std::vector<int>> board {{
    {0, 1, 1, 0, 0, 0, 1, 1},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1}
}};

int dfs(int i, int j) {

    // Check boundary & base case
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 0) 
        return 0;

    // Mark as visited
    board[i][j] = 0;

    // DFS on 8-direction offset
    int area = 1;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue; 
            area += dfs(i + di, j + dj);
        }
    }

    return area;
}

int main() {
    int maxSum = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 1) {
                maxSum = std::max(maxSum, dfs(i, j));
            }
        }
    }

    std::cout << maxSum;
}