// Time complexity -> O(n * log(max(candies)))
// Space complexity -> O(1)

class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long left = 1;
        long long right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long children_cnt = 0;

            for (int pile : candies)
            {
                children_cnt += pile / mid;
            }
            if (children_cnt >= k)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};