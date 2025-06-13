#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair <int,int>> queue1;
        vector <vector <int>> dis(n , vector<int> (n , 100000000));
        vector <vector <int>> vis(n , vector<int> (n , 0));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 1) {
                    queue1.push({i,j});
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                }
            }
        }

        int dx[4] = { 1 , -1 ,  0 , 0 };
        int dy[4] = { 0 ,  0 , -1 , 1 };

        while(!queue1.empty()) {
            pair <int,int> p = queue1.front();
            queue1.pop();

            int x = p.first;
            int y = p.second;

            for(int k = 0 ; k < 4 ; k++) {
                int newx = x + dx[k];
                int newy = y + dy[k];

                if (newx >= 0 && newx < n && newy >= 0 && newy < n) {
                    if (vis[newx][newy] == 0) {
                        queue1.push({newx,newy});
                        vis[newx][newy] = 1;
                        dis[newx][newy] = dis[x][y] + 1;
                    }
                }
            }

        }

        int maxim = 0 ;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                maxim = max(maxim , dis[i][j]);
            }
        }

        if (maxim == 100000000 || maxim == 0 ) {
            return -1;
        }

        return maxim;
    }
};
