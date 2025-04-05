class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int count = 0;

        for (int num : nums)
        {
            int complement = k - num;
            if (m[complement] > 0)
            {
                count++;
                m[complement]--;
            }
            else
            {
                m[num]++;
            }
        }
        return count;
    }
};