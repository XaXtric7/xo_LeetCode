class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int jump = 0;
        int max_h = 0;
        int current_end = 0; // Tracks the end of the current jump range

        for (int i = 0; i < n - 1; i++)
        {
            max_h = max(max_h, i + nums[i]); // Update farthest reach

            if (i == current_end)
            { // Time to jump
                jump++;
                current_end = max_h;

                if (current_end >= n - 1)
                    break; // If we can reach the last index
            }
        }
        return jump;
    }
};
