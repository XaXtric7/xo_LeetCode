class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            string str = to_string(i);
            int len = str.length();

            if (len % 2 != 0)
                continue;

            int l_sum = 0, r_sum = 0;
            for (int i = 0; i < len / 2; i++)
            {
                l_sum += str[i] - '0';
            }
            for (int i = len / 2; i < len; i++)
            {
                r_sum += str[i] - '0';
            }
            if (l_sum == r_sum)
                count++;
        }
        return count;
    }
};