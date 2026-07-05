class Solution {
long long INF = 2147483647;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if(grid[nr][nc] != INF) continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});                
            }
        }
        return;
    }
};
