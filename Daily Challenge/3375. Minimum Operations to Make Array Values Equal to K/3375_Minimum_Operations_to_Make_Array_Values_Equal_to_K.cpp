class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int min_ele = *min_element(nums.begin(), nums.end());
        if (min_ele < k)
            return -1;

        unordered_set<int> set(nums.begin(), nums.end());
        return set.size() - (min_ele == k);
    }
};