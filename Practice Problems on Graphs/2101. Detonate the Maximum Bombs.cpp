#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis, int &cnt){
        vis[node] = 1;
        cnt++;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,cnt);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n, vector<int>());

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    long long h = bombs[i][0], k = bombs[i][1], r = bombs[i][2];
                    long long x = bombs[j][0] - h, y = bombs[j][1] - k;
                    if((x*x + y*y) <= r*r){
                        adj[i].push_back(j);
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> vis(n, 0);
            int cnt = 0;
            dfs(i,adj,vis,cnt);
            ans = max(ans,cnt);
        }
        return ans;
    }
};