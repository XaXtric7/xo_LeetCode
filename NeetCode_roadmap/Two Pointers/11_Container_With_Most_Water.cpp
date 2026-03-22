class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int maxWater = 0;
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int base = right - left;
            int maxHeight = min(height[left], height[right]);
            int maxArea = maxHeight * base;
            maxWater = max(maxWater, maxArea);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxWater;
    }
};