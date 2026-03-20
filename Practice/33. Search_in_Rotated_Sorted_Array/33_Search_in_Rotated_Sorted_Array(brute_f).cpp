// My own solution was using for loop for the traversal because,
// i didn't saw the specificly asked time complexity was O(logn) ;)

// code 1 { Time complexity = O(n), Space complexity = O(1)}

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};