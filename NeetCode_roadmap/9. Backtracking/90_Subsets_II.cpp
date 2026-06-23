class Solution
{
private:
    void createSubsets(int index, vector<int> &nums, vector<int> &subsets, vector<vector<int>> &result)
    {
        result.push_back(subsets);

        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
            {
                continue;
            }

            subsets.push_back(nums[i]);
            createSubsets(i + 1, nums, subsets, result);
            subsets.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> subsets;

        createSubsets(0, nums, subsets, result);
        return result;
    }
};