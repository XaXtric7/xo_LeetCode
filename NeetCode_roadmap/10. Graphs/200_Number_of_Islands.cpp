class Solution
{
private:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited, int count)
    {
        int m = grid.size();
        int n = grid[0].size();

        visited[row][col] = 1;

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++)
        {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (grid[nr][nc] == '1' && !visited[nr][nc])
            {
                dfs(nr, nc, grid, visited, count);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(i, j, grid, visited, count);
                }
            }
        }
        return count;
    }
};