class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;

        // Step 1: Initialize queue with all 0s
        // Mark all 1s as -1 (unvisited)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {   
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        // Directions: down, up, right, left
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // Step 2: Multi-source BFS
        while (!q.empty()) {
            pair<int,int> temp = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = temp.first + dx[k];
                int ny = temp.second + dy[k];

                // If inside grid and unvisited
                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    mat[nx][ny] == -1) {

                    mat[nx][ny] = mat[temp.first][temp.second] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return mat;
    }
};
