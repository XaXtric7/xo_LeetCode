class Solution
{
private:
    bool isSafePlay(vector<string> &board, int row, int col, int n)
    {

        // same column diff row
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

    void findNQueens(int row, int n, vector<string> &board, vector<vector<string>> &result)
    {
        // base case...
        // if all the queens are placed...
        if (n == row)
        {
            result.push_back(board);
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafePlay(board, row, col, n))
            {
                board[row][col] = 'Q';
                findNQueens(row + 1, n, board, result);

                // backtrack...
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;

        findNQueens(0, n, board, result);
        return result;
    }
};