// Time complexity -> O(2^target * n)
// Space complexity -> 	O(2^target)

class Solution
{

public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        // base condition
        if (ind == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds); // store the solution and then backtrack
            }
            return;
        }
        // picking up an element
        if (arr[ind] <= target)
        {
            ds.push_back(arr[ind]); // store the data-structure and call the sunction again
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        findCombination(ind + 1, target, arr, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};