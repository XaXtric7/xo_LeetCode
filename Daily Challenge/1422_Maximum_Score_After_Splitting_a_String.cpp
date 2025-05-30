class Solution
{
public:
    int maxScore(string s)
    {
        int oneCount = 0;
        int zeroCount = 0;
        int bestScore = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '1')
            {
                oneCount++;
            }
            else
            {
                zeroCount++;
            }

            bestScore = max(bestScore, zeroCount - oneCount);
        }
        if (s[s.size() - 1] == '1')
        {
            oneCount++;
        }
        return bestScore + oneCount;
    }
};