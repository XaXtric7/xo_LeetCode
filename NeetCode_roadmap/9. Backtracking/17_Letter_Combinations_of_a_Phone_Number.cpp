class Solution
{
private:
    void backtrack(int idx, string &digits, unordered_map<char, string> &mp, string &path, vector<string> &res)
    {

        if (idx == digits.size())
        {
            res.push_back(path);
            return;
        }

        char digit = digits[idx];
        string letters = mp[digit];

        for (char c : letters)
        {
            path.push_back(c);
            backtrack(idx + 1, digits, mp, path, res);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};

        string path = "";
        backtrack(0, digits, mp, path, res);
        return res;
    }
};