// Brute Force [TLE]
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int temp = 1;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                temp *= nums[j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};