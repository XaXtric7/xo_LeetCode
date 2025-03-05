class Solution
{
public:
    long long coloredCells(int n)
    {
        long long int sum = 0;
        long long int total;
        if (n == 1)
        {
            return 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            sum += 2 * ((i * 2) + 1);
        }
        total = sum + (n + (n - 1));
        return total;
    }
};

// class Solution
// {
// public:
//     long long coloredCells(int _n)
//     {
//         unsigned long long n = _n;
//         return 1 + 2 * (n - 1) * (n);
//     }
// };