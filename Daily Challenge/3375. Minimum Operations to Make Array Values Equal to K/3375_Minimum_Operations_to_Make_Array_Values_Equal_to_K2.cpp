// Time complexity -> O(n)
// Space complexity -> O(1)
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int min_ele = *min_element(nums.begin(), nums.end());
        if (min_ele < k)
            return -1;

        bitset<10001> st;
        for (int i : nums)
        {
            if (i > k)
                st.set(i);
        }
        return st.count();
    }
};