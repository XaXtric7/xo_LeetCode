class Solution
{
private:
    bool isPal(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return isPal(left + 1, right, s) || isPal(left, right - 1, s);
            }
            left++;
            right--;
        }
        return true;
    }
};