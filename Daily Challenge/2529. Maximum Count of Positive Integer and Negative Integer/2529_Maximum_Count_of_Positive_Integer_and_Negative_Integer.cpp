// Brute-force solution (Linear search)
// Time complexity -> O(n)
// Space complexity -> O(1)

// class Solution
// {
// public:
//     int maximumCount(vector<int> &nums)
//     {
//         int n = nums.size();
//         int pos = 0, neg = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] >= 1)
//             {
//                 pos++;
//             }
//             else if (nums[i] < 0)
//             {
//                 neg++;
//             }
//         }
//         return max(pos, neg);
//     }
// };

// Optimal solution (Binary search)
// Time complexity -> O(logn)
// Space complexity -> O(1)

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int neg = bin_search(nums, 0);
        int pos = nums.size() - bin_search(nums, 1);
        return max(pos, neg);
    }

private:
    int bin_search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int result = nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }
};