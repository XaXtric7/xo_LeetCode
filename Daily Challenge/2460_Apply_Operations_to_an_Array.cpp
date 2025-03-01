class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> newNums(n, 0); // Creates a vector of size n, all elements initialized to 0, {0, 0, 0,...}
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] != 0)
            { // performs operation on non zero elements, 0's will get skipped
                if (nums[i] == nums[i + 1])
                {
                    newNums[count] = nums[i] * 2;
                    nums[i + 1] = 0;
                    i++;
                }
                else
                {
                    newNums[count] = nums[i]; // works well if last element is non zero, simply copy it in newArray.
                }
                count++;
            }
        }
        if (nums[n - 1] != 0) // Handling Last Element
        {
            newNums[count++] = nums[n - 1];
        }
        return newNums;
    }
};