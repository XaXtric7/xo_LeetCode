class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int operations = 0;
        while (!nums.empty())
        {
            unordered_set<int> seen(nums.begin(), nums.end());
            if (seen.size() == nums.size())
            { // if all distinct
                break;
            }
            int remove_ele = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + remove_ele);
            operations++;
        }
        return operations;
    }
};