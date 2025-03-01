class Solution
{
public:
    bool hasSameDigits(string s)
    {
        while (s.length() > 2)
        {
            string newStr;
            for (size_t i = 0; i < s.length() - 1; i++)
            {
                int sum = ((s[i] - '0') + (s[i + 1] - '0')) % 10; // Convert char to int before summing
                newStr += (sum + '0');                            // Convert int back to char
            }
            s = newStr; // Update s with the new transformed string
        }
        return s[0] == s[1]; // Check if the last two digits are the same
    }
};