#include <climits>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix.size();
        vector<vector<int>> grid(rows, vector<int>(columns, INT_MAX));
        queue<pair<int, int>> queue1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == 1) {
                    queue1.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }

        while (!queue1.empty()) {
            int r = queue1.front().first;
            int c = queue1.front().second;
            queue1.pop();

            int dr[] = {0, 0, -1, 1};
            int dc[] = {-1, 1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr >= 0 && rr < rows && cc >= 0 && cc < columns && grid[rr][cc] > 1 + grid[r][c]) {
                    grid[rr][cc] = 1 + grid[r][c];
                    queue1.push({rr, cc});
                }
            }
        }
        return grid;
    }
};