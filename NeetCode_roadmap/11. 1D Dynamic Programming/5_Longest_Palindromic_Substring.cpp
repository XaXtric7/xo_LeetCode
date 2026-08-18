class Solution
{
private:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
        {
            return s;
        }

        // insertion of the first element...
        int maxLen = 1;
        string maxStr = s.substr(0, 1);

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i + maxLen; j <= s.length(); j++)
            {
                if (j - i > maxLen && isPalindrome(s.substr(i, j - i)))
                {
                    maxLen = j - i;
                    maxStr = s.substr(i, j - i);
                }
            }
        }

        return maxStr;
    }
};

// using DP...

class Solution1
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();

        if (n <= 1)
            return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                if (s[i] == s[j])
                {
                    if (len == 2 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;

                        if (len > maxLen)
                        {
                            maxLen = len;
                            start = i;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};