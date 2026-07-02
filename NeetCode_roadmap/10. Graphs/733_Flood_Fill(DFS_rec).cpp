class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &image, int originalColor, int color)
    {

        int r = image.size();
        int c = image[0].size();

        image[row][col] = color;

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++)
        {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if (nr < 0 || nr >= r || nc < 0 || nc >= c)
                continue;

            if (image[nr][nc] == originalColor)
            {
                image[nr][nc] = color;
                dfs(nr, nc, image, originalColor, color);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int originalColor = image[sr][sc];
        if (originalColor == color)
            return image;
        dfs(sr, sc, image, originalColor, color);
        return image;
    }
};