// Time Complexity: O(81) = O(1) → Constant-time operation (fixed 9×9 grid).
// Space Complexity: O(81) = O(1) → Worst case, we store all 81 numbers.

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                { // skip statement
                    continue;
                }
                char value = board[r][c];
                int boxIndex = (r / 3) * 3 + (c / 3); // determines which box the cell belongs to.

                if (rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value))
                { // Check if value already exists
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;
    }
};