// Time complexity -> O(n * n!)
// Space complexity -> O(n)

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;

        // If there is only one integer in the given array
        if (nums.size() == 1)
        {
            vector<int> singleList;
            singleList.push_back(nums[0]);
            res.push_back(singleList);
            return res;
        }
        // More than one integer in te given array
        for (int i = 0; i < nums.size(); i++)
        {                    // traversing through the given array
            int n = nums[i]; // storing the first number
            vector<int> remainingNums;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j != i)
                {
                    remainingNums.push_back(nums[j]);
                }
            }

            vector<vector<int>> perms = permute(remainingNums); // backtracking
            for (vector<int> p : perms)
            {                           // use of ranged-based for loop
                p.insert(p.begin(), n); // Insert n at the beginning of the permutation
                res.push_back(p);       // Append the modified permutation to the result
            }
        }
        return res;
    }
};