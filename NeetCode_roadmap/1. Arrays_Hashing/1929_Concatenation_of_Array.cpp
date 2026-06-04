class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        ans.insert(ans.end(), nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

// Optimization...

class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};