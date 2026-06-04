// Naive approach..
// find the max element in the array and term it as maxSpeed
// from 1 to maxSpeed use a for loop and for each speed find the req time to finish the bananas

int kokoEat(vector<int> &arr, int k)
{
    int mx = *max_element(arr.begin(), arr.end());
    for (int speed = 1; speed <= mx; speed++)
    {
        long long reqTime = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            reqTime += (arr[i] + speed - 1) / speed;
        }
        if (reqTime <= k)
        {
            return speed;
        }
    }
    return mx;
}

// Optimal solution....

class Solution
{
private:
    bool canFinish(vector<int> &piles, int h, int k)
    {
        long long hours = 0;
        for (int pile : piles)
        {
            hours += pile / k;
            if (pile % k != 0)
                hours++;
            if (hours > h)
                return false;
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};