#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> traversed;
        int result = 0;
        for(int i = 0 ; i < isConnected.size(); ++i){
            if(traversed.find(i) == traversed.end()){
                dfs(isConnected, traversed, i);
                result++;
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& isConnected, set<int> &traversed, int i) {
        if(traversed.find(i) != traversed.end()) {
            return;
        }
        traversed.insert(i);
        for(int j = 0; j < isConnected[i].size(); ++j){
            if(isConnected[i][j] == 1) {
                dfs(isConnected, traversed, j);
            }
        }
    }
};