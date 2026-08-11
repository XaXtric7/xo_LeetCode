// using memoization...

class Solution1
{
private:
    int memo(int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = memo(n - 1, dp) + memo(n - 2, dp);
    }

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return memo(n, dp);
    }
};

// using space optimization ...

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 0)
            return 0;
        if (n <= 1)
            return 1;

        int prev1 = 1, prev2 = 1;

        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};