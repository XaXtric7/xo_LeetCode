class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> dups;
        for (int i = 0; i < n; i++)
        {
            dups.insert(nums[i]);
        }
        int size = dups.size();
        if (size != n)
            return true;
        return false;
    }
};