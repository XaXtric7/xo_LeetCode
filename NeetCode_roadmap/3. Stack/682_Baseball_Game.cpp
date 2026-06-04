class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        for (auto op : operations)
        {
            if (op == "C")
                st.pop();
            else if (op == "D")
                st.push(2 * st.top());
            else if (op == "+")
            {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                int sum = top1 + top2;
                st.push(top1);
                st.push(sum);
            }
            else
            {
                st.push(stoi(op));
            }
        }
        int total = 0;
        while (!st.empty())
        {
            total += st.top();
            st.pop();
        }
        return total;
    }
};