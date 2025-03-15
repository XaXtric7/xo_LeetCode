class Solution
{
public:
    int totalNumbers(vector<int> &digits)
    {
        int n = digits.size();
        set<int> u_numbers;
        for (int i = 0; i < n; i++)
        {
            if (digits[i] == 0)
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    if (digits[k] % 2 == 0)
                    { // even
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        u_numbers.insert(num);
                    }
                }
            }
        }
        return u_numbers.size();
    }
};