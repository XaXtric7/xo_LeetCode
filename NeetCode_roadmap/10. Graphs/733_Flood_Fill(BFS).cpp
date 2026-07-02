class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        int originalColor = image[sr][sc];

        if (originalColor == color)
            return image;

        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});

        image[sr][sc] = color;

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols &&
                    image[nr][nc] == originalColor)
                {

                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};