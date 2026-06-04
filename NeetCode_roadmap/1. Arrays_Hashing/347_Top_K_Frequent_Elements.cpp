
// Using prioriority Queue...
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        for (int x : nums)
        {
            freq[x]++;
        }

        // min heap: {frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : freq)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
            {
                pq.pop(); // remove smallest frequency
            }
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

// Using Bucket Sort....
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : freq)
        {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;

        for (int i = nums.size(); i >= 0 && ans.size() < k; i--)
        {
            for (int num : bucket[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};