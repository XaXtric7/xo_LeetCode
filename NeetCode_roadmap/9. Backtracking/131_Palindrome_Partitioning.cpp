class Solution
{
private:
    bool isPalindrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(int index, string &s, vector<string> &path, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;

        backtrack(0, s, path, res);
        return res;
    }
};