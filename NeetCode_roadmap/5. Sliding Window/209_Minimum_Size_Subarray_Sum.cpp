class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minVal = INT_MAX;
        int n = nums.size();
        int left = 0;
        int sum = 0;
        for (int right = 0; right < n; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minVal = min(minVal, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        if (minVal == INT_MAX)
        {
            return 0;
        }
        return minVal;
    }
};