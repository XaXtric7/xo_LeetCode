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

        for (int i = index; i < candidates.size(); i++)
        {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue further
            if (candidates[i] > target)
                break;

            nums.push_back(candidates[i]);

            findSum(i + 1, target - candidates[i], candidates, nums, ans);

            nums.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> nums;

        findSum(0, target, candidates, nums, ans);

        return ans;
    }
};