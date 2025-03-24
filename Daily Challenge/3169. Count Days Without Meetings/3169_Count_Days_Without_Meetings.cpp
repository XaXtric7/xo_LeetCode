// TLE
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        vector<bool> occupied(days + 1, false);

        for (auto meeting : meetings)
        {
            for (int d = meeting[0]; d <= meeting[1]; d++)
            {
                occupied[d] = true;
            }
        }
        int freedays = 0;
        for (int d = 1; d <= days; d++)
        {
            if (!occupied[d])
            {
                ++freedays;
            }
        }
        return freedays;
    }
};