#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    int countMines(const vector<vector<char>>& board, const vector<int>& cell) {
        int mines = 0;
        size_t m = board.size();
        size_t n = board.front().size();
        int x = cell[0];
        int y = cell[1];

        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i < 0 || i >= static_cast<int>(m)) continue;
                if (j < 0 || j >= static_cast<int>(n)) continue;
                if (board[i][j] == 'M') ++mines;
            }
        }
        return mines;
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> result = board;
        queue<vector<int>> q;
        q.push(click);

        size_t m = board.size();
        size_t n = board.front().size();

        while (!q.empty()) {
            vector<int> cell = q.front();
            q.pop();

            int x = cell[0];
            int y = cell[1];
            char& current = result[x][y];

            if (current == 'M') {
                current = 'X';
            } else if (current == 'E') {
                int mines = countMines(board, cell);
                if (mines != 0) {
                    current = static_cast<char>('0' + mines);
                } else {
                    current = 'B';
                    for (int i = x - 1; i <= x + 1; ++i) {
                        for (int j = y - 1; j <= y + 1; ++j) {
                            if (i < 0 || i >= static_cast<int>(m)) continue;
                            if (j < 0 || j >= static_cast<int>(n)) continue;
                            q.push({i, j});
                        }
                    }
                }
            }
        }
        return result;
    }
};

