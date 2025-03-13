// Time complexity -> O(n*m)
// Space complexity -> O(1)

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int x = 0;
        int y = 0;
        int dx = 1;
        int dy = 0;
        vector<int> ans;
        // right => dx = 1, dy = 0,
        // down  => dx = 0, dy = 1,
        // left  => dx = -1, dy = 0,
        // up    => dx = 0, dy = -1,

        for (int i = 0; i < rows * cols; i++)
        {
            ans.push_back(matrix[y][x]);
            matrix[y][x] = -101;

            if (!(0 <= x + dx && x + dx < cols && 0 <= y + dy && y + dy < rows) || matrix[y + dy][x + dx] == -101)
            {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            x += dx;
            y += dy;
        }
        return ans;
    }
};