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

// Optimized...
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefix = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};