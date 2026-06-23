class Solution
{
private:
    void findSum(int index, int target, vector<int> &candidates, vector<int> &nums, vector<vector<int>> &ans)
    {
        // base case...
        if (target == 0)
        {
            ans.push_back(nums);
            return;
        }
        if (index == candidates.size() || target < 0)
        {
            return;
        }

        // pick...
        nums.push_back(candidates[index]);
        findSum(index, target - candidates[index], candidates, nums, ans);

        // notpick...
        nums.pop_back();
        findSum(index + 1, target, candidates, nums, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> nums;

        findSum(0, target, candidates, nums, ans);

        return ans;
    }
};