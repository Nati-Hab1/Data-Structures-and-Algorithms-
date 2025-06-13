#include <queue>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> map;
        for(string s: wordList){
            map[s]++;
        }
        queue<pair<string,int>> queue1;
        queue1.push({beginWord,1});
        if(map[beginWord] > 0) map[beginWord]--;

        while(!queue1.empty()){
            string sf = queue1.front().first;
            int d = queue1.front().second;
            if(sf == endWord) return d;
            queue1.pop();

            for(int i = 0; i < sf.size();i++){
                string t = sf;
                for(int j = 0; j < 26; j++){
                    t[i] = 'a' + j;
                    if(map[t] > 0){
                        queue1.push({t,d+1});
                        map[t]--;
                    }
                }
            }
        }

        return 0;
    }
};