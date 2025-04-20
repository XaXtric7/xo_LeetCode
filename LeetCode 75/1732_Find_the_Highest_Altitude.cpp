// 1732_Find_the_Highest_Altitude
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int curr_alt = 0;
        int max_alt = 0;
        for (int i : gain)
        {
            curr_alt += i;
            max_alt = max(max_alt, curr_alt);
        }
        return max_alt;
    }
};