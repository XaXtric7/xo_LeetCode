class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.length();
        int min_recolors = k; // Maximum recolors needed in worst case

        // Count initial 'W's in the first window
        int white_count = 0;
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                white_count++;
        }

        min_recolors = white_count;

        // Slide the window across the string
        for (int i = k; i < n; i++)
        {
            // Remove leftmost element of previous window
            if (blocks[i - k] == 'W')
                white_count--;
            // Add rightmost element of current window
            if (blocks[i] == 'W')
                white_count++;

            // Update the minimum number of recolors needed
            min_recolors = min(min_recolors, white_count); // mininimum of (intital white_counts in the begining, white_count in the window)
        }

        return min_recolors;
    }
};
