// Time complexity -> O(n)
// Space complexity -> O(n)

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        vector<int> left, equal, right;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                left.push_back(nums[i]);
            }
            else if (nums[i] > pivot)
            {
                right.push_back(nums[i]);
            }
            else if (nums[i] == pivot)
            {
                equal.push_back(nums[i]);
            }
        }
        // array concatenation
        left.insert(left.end(), equal.begin(), equal.end()); // attach left array with equal
        left.insert(left.end(), right.begin(), right.end()); // attach updated left with equal

        return left;
    }
};