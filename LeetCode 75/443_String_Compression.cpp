class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n)
        {
            char current_char = chars[i];
            int count = 0;

            while (i < n && chars[i] == current_char)
            {
                i++;
                count++;
            }
            chars[write++] = current_char;
            if (count > 1)
            {
                string count_str = to_string(count);
                for (char c : count_str)
                {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};