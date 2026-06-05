class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        int n = s1.size();
        int m = s2.size();

        for (char c : s1)
        {
            freq1[c - 'a']++;
        }

        for (int right = 0; right < m; right++)
        {
            freq2[s2[right] - 'a']++;
            if (right >= n)
            { // have to remove the elements
                freq2[s2[right - n] - 'a']--;
            }
            if (freq1 == freq2)
            {
                return true;
            }
        }
        return false;
    }
};