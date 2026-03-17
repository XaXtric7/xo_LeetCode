class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == target - nums[i])
                {
                    return {i, j};
                }
            }
        }
        // Return an empty vector if no solution is found
        return {};
    }
};

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int comp = target - nums[i];
            if (numMap.count(comp))
            {
                return {numMap[comp], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int comp = target - nums[i];

            // find
            if (mp.find(comp) != mp.end())
            {
                return {mp[comp], i};
            }

            // store values in mp
            mp[nums[i]] = i;
        }
        return {};
    }
};