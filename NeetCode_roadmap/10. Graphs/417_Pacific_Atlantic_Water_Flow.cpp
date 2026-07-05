class Solution
{
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>> &heights,
             vector<vector<bool>> &vis)
    {

        vis[r][c] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c])
            {

                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific (top row)
        for (int c = 0; c < n; c++)
            dfs(0, c, heights, pacific);

        // Pacific (left column)
        for (int r = 0; r < m; r++)
            dfs(r, 0, heights, pacific);

        // Atlantic (bottom row)
        for (int c = 0; c < n; c++)
            dfs(m - 1, c, heights, atlantic);

        // Atlantic (right column)
        for (int r = 0; r < m; r++)
            dfs(r, n - 1, heights, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};