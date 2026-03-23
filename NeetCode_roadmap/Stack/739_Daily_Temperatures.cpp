class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);
        }
        return ans;
    }
};