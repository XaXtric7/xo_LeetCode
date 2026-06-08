class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int up = 1;
        int down = 1;
        int ans = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > arr[i - 1])
            {
                up = down + 1;
                down = 1;
            }
            else if (arr[i] < arr[i - 1])
            {
                down = up + 1;
                up = 1;
            }
            else
            {
                up = down = 1;
            }
            ans = max(ans, max(up, down));
        }
        return ans;
    }
};