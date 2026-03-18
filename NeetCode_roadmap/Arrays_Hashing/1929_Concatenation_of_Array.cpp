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