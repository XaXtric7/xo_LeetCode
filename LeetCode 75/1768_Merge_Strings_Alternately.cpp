class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        string blend = "";
        int i = 0;
        while (i < n || i < m)
        {
            if (i < n)
            {
                blend += word1[i];
            }
            if (i < m)
            {
                blend += word2[i];
            }
            i++;
        }
        return blend;
    }
};