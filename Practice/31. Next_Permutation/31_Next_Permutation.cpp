class Solution
{
public:
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size();
        int index = -1;

        // Step 1: Find the breach point (rightmost index where arr[i] < arr[i+1])
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                index = i;
                break;
            }
        }

        // Step 2: If no breach point found, reverse the entire array
        if (index == -1)
        {
            reverse(arr.begin(), arr.end());
            return;
        }

        // Step 3: Find the rightmost element greater than arr[index] and swap
        for (int i = n - 1; i > index; i--)
        {
            if (arr[i] > arr[index])
            {
                swap(arr[i], arr[index]);
                break;
            }
        }

        // Step 4: Reverse the elements after the breach index
        reverse(arr.begin() + index + 1, arr.end());
    }
};