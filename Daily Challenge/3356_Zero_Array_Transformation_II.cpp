#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();        // size of the nums
        vector<int> diff(n + 1, 0); // diff vector to optimize
        int sum = 0;
        int pos = 0;

        for (int i = 0; i < n; ++i)
        { // looping inside the nums array
            while (sum + diff[i] < nums[i])
            {
                if (pos == queries.size()) // task cannot be done
                    return -1;

                int l = queries[pos][0];
                int r = queries[pos][1];
                int val = queries[pos][2];
                ++pos;

                if (r < i)
                    continue;

                diff[max(l, i)] += val;
                diff[r + 1] -= val;
            }
            sum += diff[i];
        }
        return pos;
    }
};
