class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int jumps = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (i > jumps)
                return false;                // If we can't reach index i, return false
            jumps = max(jumps, i + nums[i]); // Update the farthest reachable index
            if (jumps >= n - 1)
                return true; // If we can reach the last index, return true
        }
        return false;
    }
};
