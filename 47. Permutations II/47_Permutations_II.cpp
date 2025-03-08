// Time complexity -> O(n * n!)
// Space complexity -> O(n * n!)

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &result, vector<int> &temp, vector<bool> &used)
    {
        if (temp.size() == nums.size())
        {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue; // Skip if already used
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue; // Avoid duplicate permutations

            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, result, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(nums, result, temp, used);
        return result;
    }
};
