class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int cnt = 0;
        for (int num : nums)
        {
            int digits = 0;
            int n = num;
            while (n > 0)
            {
                digits++;
                n /= 10;
            }
            if (digits % 2 == 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};