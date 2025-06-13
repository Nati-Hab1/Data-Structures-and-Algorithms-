#include<iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> queue1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (mat[i][j] == 0) {
                    queue1.push({i, j});
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while (!queue1.empty()) {
            pair<int, int> cell = queue1.front();
            queue1.pop();
            int row = cell.first;
            int col = cell.second;

            for (pair<int, int> direction : directions) {
                int newRow = row + direction.first;
                int newCol = col + direction.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && mat[newRow][newCol] > mat[row][col] + 1) {
                    mat[newRow][newCol] = mat[row][col] + 1;
                    queue1.push({newRow, newCol});
                }
            }
        }

        return mat;
    }
};