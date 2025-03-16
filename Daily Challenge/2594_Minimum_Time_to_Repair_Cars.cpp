// Time complexity -> ≈ O(n*log(m))
// Space complexity -> 	O(1)

class Solution
{
public:
    bool enough_time(vector<int> &ranks, int cars, long long mid_obt)
    {
        long long cars_done = 0;
        for (int r : ranks)
        {
            long long c2 = mid_obt / r;
            long long c = floor(sqrt(c2));
            cars_done += c;
        }
        return cars_done >= cars;
    }
    long long repairCars(vector<int> &ranks, int cars)
    {
        long long left = 1;
        long long right = 1e14;
        while (left < right)
        {
            long long mid = left + (right - left) / 2;
            if (enough_time(ranks, cars, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};