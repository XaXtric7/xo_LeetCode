// This is the brute force solution
// Time Complexity -> O(n)
// Space Complexity -> O(1)
// Using Linear Search

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans1 = -1, ans2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                ans1 = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                ans2 = i;
                break;
            }
        }
        return {ans1, ans2};
    }
};