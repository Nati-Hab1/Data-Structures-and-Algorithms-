#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    void build(vector<vector<string>>& equations, vector<double>& values,
               map<string,map<string,double>> &graph){

        int i = 0;
        for(vector<string> equ : equations){
            string first = equ[0];
            string second = equ[1];

            double val = values[i];
            i++;
            graph[first][second] = val;
            graph[second][first] = 1/val;

        }

    }
    double dfs(map<string,map<string,double>> &graph,string srtEl,string endEl,unordered_set<string> &visited){
        if(graph.count(srtEl) == 0) return -1.0;
        cout<<srtEl<<endl;
        if(graph[srtEl].count(endEl)){
            return graph[srtEl][endEl];
        }

        visited.insert(srtEl);
        map<string,double> edges = graph[srtEl];

        for(auto &x : edges){

            if(visited.count(x.first) == 0){
                double val = dfs(graph,x.first,endEl,visited);
                if(val != -1.0)
                    return val * x.second;

            }


        }

        return -1.0 ;

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,map<string,double>> graph;
        build(equations,values,graph);
        vector<double> results;

        for(vector<string> query : queries){

            if(query[0] == query[1]){

                if(graph.count(query[0])){
                    results.push_back(1.0);
                }
                else{
                    results.push_back(-1.0);
                }

                continue;
            }

            unordered_set<string> visited;
            results.push_back(dfs(graph,query[0],query[1],visited));
        }


        return results;
    }
};
