#include <vector>

// O(1) time:
// Scanning chess board is O(8 * 8) then scanning directions is O(4 * 8)

// O(1) space:
// Only some variables, and nice that board is passed by reference as well.

class Solution {
public:
    int numRookCaptures(std::vector<std::vector<char>>& board) {

        int rookR, rookC;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'R') {
                    rookR = i, rookC = j;
                    goto found;
                }
            }
        }

        found:

        std::vector<int> dx = {-1, 1, 0, 0};
        std::vector<int> dy = {0, 0, -1, 1};

        int attacking{};
        for (int i = 0; i < 4; i++) {
            int nx = rookR + dx[i];
            int ny = rookC + dy[i];

            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (board[nx][ny] == 'p') {
                    attacking++;
                    break;
                }
                if (board[nx][ny] == 'B') {
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            } 
        }
        return attacking;
    }
};