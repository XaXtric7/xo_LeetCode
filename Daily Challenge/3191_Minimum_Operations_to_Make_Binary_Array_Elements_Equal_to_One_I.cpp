// Time complexity -> ≈ O(n)
// Space complexity -> 	O(1)

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        { // loop stops on 3rd last element
            if (nums[i] == 0)
            {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1; // 3rd consec.
                count++;
            }
        }
        for (int num : nums)
        { // for every num in nums
            if (num == 0)
            {
                return -1;
            }
        }
        return count;
    }
};