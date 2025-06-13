#include <iostream>
#include <vector>
using namespace std;

int mx[4] = {-1, 0, 1, 0};
int my[4] = {0, 1, 0, -1};

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int t = 0;

        while(true) {

            int cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 2) {
                        for(int p = 0; p < 4; p++) {
                            int nx = i+mx[p];
                            int ny = j+my[p];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                                grid[nx][ny] = -1;
                                cnt += 1;
                            }
                        }
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] = (grid[i][j] == -1 ? 2 : grid[i][j]);
                }
            }

            if(cnt == 0) {
                break;
            }

            t += 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return t;
    }
};
