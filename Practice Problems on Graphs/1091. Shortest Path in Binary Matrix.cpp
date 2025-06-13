#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int, int>> possibleDirections = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

        int size = grid.size();

        if (grid[0][0] != 0 || grid[size - 1][size - 1] != 0)
            return -1;

        queue<pair<int,int>> queue1;
        queue1.push({0, 0});
        grid[0][0] = 1;

        while (!queue1.empty()) {
            pair<int, int> current_coordinates = queue1.front();
            queue1.pop();

            int row = current_coordinates.first;
            int column = current_coordinates.second;
            int distance = grid[row][column];


            if (row == size - 1 && column == size - 1)
                return distance;

            for (auto &dir : possibleDirections) {
                int old_row = dir.first;
                int old_column = dir.second;

                int new_row = row + old_row;
                int new_column = column + old_column;

                if (new_row >= 0 && new_row < size && new_column >= 0 && new_column < size && grid[new_row][new_column] == 0) {
                    queue1.push({new_row, new_column});
                    grid[new_row][new_column] = distance + 1;
                }
            }
        }

        return -1;

    }
};