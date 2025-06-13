#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        int MAX = n * n;
        queue<int> q;
        q.push(1);
        vector<bool> visited(MAX + 1, false);
        visited[1] = true;

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                if (curr == MAX)
                    return level;

                for (int next = curr + 1; next <= min(curr + 6, MAX); ++next) {
                    int dest = next;
                    int row = (next - 1) / n;
                    int column = (next - 1) % n;
                    if (row % 2 == 1)
                        column = n - 1 - column;

                    row = n - 1 - row;

                    if (board[row][column] != -1)
                        dest = board[row][column];

                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.push(dest);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};