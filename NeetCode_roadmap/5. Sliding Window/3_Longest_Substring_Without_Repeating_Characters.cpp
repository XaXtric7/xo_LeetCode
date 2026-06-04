class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int left = 0;
        int ans = 0;
        int n = s.size();

        for (int right = 0; right < n; right++)
        {
            while (st.count(s[right]))
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};