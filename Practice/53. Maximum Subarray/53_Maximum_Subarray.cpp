class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0]; // initial value
        int total = 0;

        for (int n : nums)
        { // range based for loop
            if (total < 0)
            {              // if a negative no. comes up
                total = 0; // re-set the value
            }
            total += n;            // add if positive
            res = max(res, total); // checking max of res and total in each loop
        }
        return res;
    }
};