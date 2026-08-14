class Solution
{
private:
    int memo(int index, vector<int> &newArray, vector<int> &dp)
    {
        int n = newArray.size();
        if (index > n - 1)
            return 0;
        if (index == n - 1)
            return newArray[index];
        if (dp[index] != -1)
            return dp[index];

        int pick = newArray[index] + memo(index + 2, newArray, dp);
        int notPick = memo(index + 1, newArray, dp);

        return dp[index] = max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp1;
        vector<int> temp2;
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }
        return max(memo(0, temp1, dp1), memo(0, temp2, dp2));
    }
};