// My Solution...
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (int num : st)
        {
            if (st.find(num - 1) == st.end()) // if prev element not exist then proceed with the follwing code
            {
                int currentNum = num; // number which is the start of the sequence
                int count = 1;
                while (st.find(currentNum + 1) != st.end())
                { // if next term exist then proceed wiht the code below
                    currentNum++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};