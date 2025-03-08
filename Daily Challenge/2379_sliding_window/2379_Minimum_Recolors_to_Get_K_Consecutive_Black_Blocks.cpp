class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length(); // stores the lenght of the string
        int recolor = INT_MAX;   // initialized to the max integer value
        int black_cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (blocks[i] == 'B')
            { // skip the white and only focus on the black
                black_cnt++;
            }
            if (i >= k - 1)
            { // can form a valid window
                recolor = min(k - black_cnt, recolor);
                if (blocks[i - k + 1] == 'B')
                {
                    black_cnt--;
                }
            }
        }
        return recolor;
    }
};