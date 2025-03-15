// Time Complexit -> O(n*log(m))
// Space Complexity -> O(1)

class Solution
{
private:
    int is_valid(const vector<int> &nums, int k, int capability)
    {
        int i = 0;
        int cnt = 0;
        while (i < nums.size())
        {
            if (nums[i] <= capability)
            {
                i += 2;
                cnt++;
            }
            else
            {
                i++;
            }
            if (cnt == k)
            {
                break;
            }
        }
        return cnt == k;
    }

public:
    int minCapability(vector<int> &nums, int k)
    {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int res = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (is_valid(nums, k, mid))
            {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return res;
    }
};