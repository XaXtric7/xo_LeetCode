class Solution
{
private:
    int recursion(int index, vector<int> &nums)
    {
        int size = nums.size();
        if (index >= size)
            return 0;
        int rob = nums[index] + recursion(index + 2, nums);
        int skip = recursion(index + 1, nums);

        return max(rob, skip);
    }

public:
    int rob(vector<int> &nums)
    {
        // using recursion...
        return recursion(0, nums);
    }
};

// using memoization...

class Solution
{
private:
    int memo(int index, vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();
        if (index > n - 1)
            return 0;
        if (index == n - 1)
            return nums[index];
        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] + memo(index + 2, nums, dp);
        int notPick = memo(index + 1, nums, dp);

        return dp[index] = max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return memo(0, nums, dp);
    }
};

// using space optimization...

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i] + prev2;
            int notTake = 0 + prev1;
            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};