#include <vector>
#include <set>
#include <stack>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        stack<int> stack1;

        visited.insert(0);
        for(const auto& element:rooms[0]){
            stack1.push(element);
        }

        while(!stack1.empty()){
            int current_room = stack1.top();
            stack1.pop();
            if (visited.find(current_room) == visited.end()){
                visited.insert(current_room);
                for(const auto& element:rooms[current_room]){
                    stack1.push(element);
                }
            }
        }

        return (visited.size() == rooms.size());

    }
};
