class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int total = n1 + n2;
        int half = (total + 1) / 2;

        int left = 0;
        int right = n1;

        while (left <= right)
        {

            int i = left + (right - left) / 2;
            int j = half - i;

            int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == n1) ? INT_MAX : nums1[i];

            int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n2) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright)
            {

                if (total % 2)
                {
                    return max(Aleft, Bleft);
                }

                return (max(Aleft, Bleft) +
                        min(Aright, Bright)) /
                       2.0;
            }

            else if (Aleft > Bright)
            {
                right = i - 1;
            }

            else
            {
                left = i + 1;
            }
        }

        return 0.0;
    }
};