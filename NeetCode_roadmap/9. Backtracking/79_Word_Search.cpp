class Solution {
private:
    bool backtrack(int r, int c, int index, vector<vector<char>> &board, string &word){

        int rows = board.size();
        int cols = board[0].size();

        // base case...
        if(index == word.size()){
            return true; // index will only increment when word is found...
        }

        // out of bounds and word match check...
        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[index]){
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; //visited

        bool found =
            backtrack(r + 1, c, index + 1, board, word) ||
            backtrack(r - 1, c, index + 1, board, word) ||
            backtrack(r, c + 1, index + 1, board, word) ||
            backtrack(r, c - 1, index + 1, board, word);

        board[r][c] = temp; //restore

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(backtrack(r, c, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};