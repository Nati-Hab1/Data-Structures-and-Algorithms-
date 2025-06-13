#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};

    bool bound(int i,int j,int r,int c){
        return (i<r && j<c && i>=0 && j>=0);
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        queue<pair<int,int>> queue1;

        queue1.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';

        int steps=0;
        while(!queue1.empty()){
            int sizez = queue1.size();
            ++steps;
            while(sizez--){
                auto node=queue1.front();
                queue1.pop();

                for(int x=0;x<4;++x){
                    int new_i = node.first+dx[x];
                    int new_j = node.second+dy[x];

                    if(bound(new_i,new_j,r,c)){
                        if(maze[new_i][new_j]=='.' && (new_i==0 || new_i==r-1 || new_j==0 || new_j==c-1) )return steps;

                        if(maze[new_i][new_j]=='.'){
                            queue1.push({new_i,new_j});
                            maze[new_i][new_j]='+';
                        }

                    }
                }

            }
        }
        return -1;
    }
};