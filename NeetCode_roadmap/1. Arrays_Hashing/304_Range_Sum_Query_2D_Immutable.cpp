// My solution [TLE]
// Brute Force...

class NumMatrix
{
public:
    vector<vector<int>> temp_mat;
    NumMatrix(vector<vector<int>> &matrix)
    {
        temp_mat = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                sum += temp_mat[i][j];
            }
        }
        return sum;
    }
};

// Optimal solution...

class NumMatrix
{
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        prefix.assign(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};