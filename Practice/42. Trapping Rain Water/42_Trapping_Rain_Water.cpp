// Time complexity -> O(n)
// Space complexity -> 	O(1)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int leftmax = height[left];
        int rightmax = height[right];
        int water = 0;

        while (left < right)
        {
            if (leftmax < rightmax)
            {
                left++;
                leftmax = max(leftmax, height[left]);
                water += leftmax - height[left];
            }
            else
            {
                right--;
                rightmax = max(rightmax, height[right]);
                water += rightmax - height[right];
            }
        }
        return water;
    }
};