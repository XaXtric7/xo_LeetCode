class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int suffixSum = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            suffixSum -= nums[i];
            if (suffixSum == prefixSum)
                return i;
            prefixSum += nums[i];
        }
        return -1;
    }
};