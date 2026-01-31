class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        // Mark entrance as visited
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        // 4 directions
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // BFS
        while (!q.empty()) {
            int size = q.size();
            steps++;

            for (int s = 0; s < size; s++) {
                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Check bounds and open path
                    if (nx >= 0 && ny >= 0 &&
                        nx < m && ny < n &&
                        maze[nx][ny] == '.') {

                        // If boundary cell and not entrance → exit found
                        if (nx == 0 || ny == 0 || nx == m - 1 || ny == n - 1) {
                            return steps;
                        }

                        // Mark visited and continue BFS
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }

        // No exit reachable
        return -1;
    }
};
