#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) {
            return 0;
        }
        unordered_map<int, unordered_set<int>> to_route;
        for (int i = 0; i < routes.size(); ++i) {
            for (const auto& stop : routes[i]) {
                to_route[stop].emplace(i);
            }
        }

        int result = 1;
        vector<int> q{S};
        unordered_set<int> lookup{S};
        unordered_set<int> visited_routes;

        while (!q.empty()) {
            vector<int> next_q;
            for (const auto& stop : q) {
                for (const auto& i : to_route[stop]) {
                    if (visited_routes.count(i)) continue;
                    visited_routes.insert(i);

                    for (const auto& next_stop : routes[i]) {
                        if (lookup.count(next_stop)) {
                            continue;
                        }
                        if (next_stop == T) {
                            return result;
                        }
                        next_q.emplace_back(next_stop);
                        to_route[next_stop].erase(i);
                        lookup.emplace(next_stop);
                    }
                }
            }
            swap(q, next_q);
            ++result;
        }
        return -1;
    }
};