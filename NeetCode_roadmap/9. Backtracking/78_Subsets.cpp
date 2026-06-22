class Solution
{
private:
    void createSubset(vector<int> &nums, int index, vector<vector<int>> &result, vector<int> &subset)
    {
        if (index == nums.size())
        {
            result.push_back(subset);
            return;
        }
        // pick...
        subset.push_back(nums[index]);
        createSubset(nums, index + 1, result, subset);

        // notPick...
        subset.pop_back();
        createSubset(nums, index + 1, result, subset);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subset;

        createSubset(nums, 0, result, subset);
        return result;
    }
};