// Time complexity -> ≈ O(n)
// Space complexity -> 	O(1)

class Solution
{
public:
    int numberOfAlternatingGroups(std::vector<int> &colors, int k)
    {
        int N = colors.size(); // size of the colors array
        int l = 0, res = 0;

        for (int r = 1; r < N + k - 1; ++r)
        { // prevents from the seq. getting repeated
            if (colors[r % N] == colors[(r - 1) % N])
            {          // counter out-of-bounds case
                l = r; // if not alternating the whole window will be invalid
            }
            if (r - l + 1 > k)
            {           // the window will not be greater than the size
                l += 1; // if happens shrink the window by one
            }
            if (r - l + 1 == k)
            { // assuming its alternating
                res += 1;
            }
        }
        return res;
    }
};