#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, -1);
        return solve(target,dp);
    }

    int solve(int target,vector<int>& dp){
        if(dp[target]!=-1){
            return dp[target];
        }

        int n = floor( log2 (target) ) + 1;
        if((1<<n)-1==target){
            return n;
        }

        int result = n + 1 + solve ((1 << n) - 1 - target, dp);

        for(int i=0; i<n-1; i++){
            int distance = (1 << (n - 1)) - (1 << i);
            result = min(result, n + i + 1 + solve(target - distance, dp));
        }

        dp[target] = result;
        return result;
    }
};
