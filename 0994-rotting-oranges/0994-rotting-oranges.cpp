class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        int minutes = 0;

        // initialization
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // BFS
        while(!q.empty() && fresh > 0){
            int levelSize = q.size();
            while(levelSize--){
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && ny >= 0 && nx < m && ny < n &&
                       grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }

        return (fresh == 0) ? minutes : -1;
    }
};
