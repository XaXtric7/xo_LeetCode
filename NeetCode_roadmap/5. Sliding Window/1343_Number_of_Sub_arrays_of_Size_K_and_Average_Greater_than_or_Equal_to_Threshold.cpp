class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        int n = arr.size();
        int sum = 0;
        int ans = 0;

        for (int right = 0; right < n; right++)
        {
            sum += arr[right];

            if (right >= k)
            {
                sum -= arr[right - k];
            }

            if (right >= k - 1)
            {
                if (sum >= k * threshold)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};