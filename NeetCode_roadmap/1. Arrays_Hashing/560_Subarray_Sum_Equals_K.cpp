// My solution.. O(n^2)
class Solution
{
private:
    int fRecur(int ind, vector<int> &nums, int k, int n)
    {
        int cnt = 0;
        int sum = 0;
        for (int i = ind; i < n; i++)
        {
            sum += nums[i];
            if (sum == k)
                cnt++;
        }
        return cnt;
    }

public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += fRecur(i, nums, k, n);
        }
        return count;
    }
};

// Optimized O(n)...
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums)
        {
            sum += num;
            if (mp.find(sum - k) != mp.end())
            {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};