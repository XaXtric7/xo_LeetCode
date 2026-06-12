class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (st.count(nums[i]))
            {
                return nums[i];
            }
            st.insert(nums[i]);
        }
        return -1;
    }
};