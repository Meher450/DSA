class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::vector<bool> visited(rooms.size(), false);
        size_t rooms_visited = 1;
        std::vector<int> stack;
        stack.push_back(0);
        visited[0] = true;

        while(!stack.empty())
        {
            const auto current_room = stack.back();
            stack.pop_back();

            for(auto adj : rooms[current_room])
            {
                if(!visited[adj])
                {
                    ++rooms_visited;
                    visited[adj] = true;
                    stack.emplace_back(adj);
                }
            }
        }
        

        return rooms_visited == rooms.size();
    }
};