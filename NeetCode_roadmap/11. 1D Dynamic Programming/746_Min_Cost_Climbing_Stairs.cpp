// using memoization...

class Solution1
{
private:
    int minCost(int index, vector<int> &cost, vector<int> &dp)
    {
        int n = cost.size();
        if (index >= n)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int oneStep = minCost(index + 1, cost, dp);
        int twoStep = minCost(index + 2, cost, dp);

        return dp[index] = cost[index] + min(oneStep, twoStep);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(minCost(0, cost, dp), minCost(1, cost, dp));
    }
};

// using space optimization...

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        int prev1 = cost[1], prev2 = cost[0];
        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(prev1, prev2);

            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};