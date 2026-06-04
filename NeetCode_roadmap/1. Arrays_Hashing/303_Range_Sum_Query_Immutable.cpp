// Brute Force...

class NumArray
{
private:
    vector<int> nums;

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
    }

    int sumRange(int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            sum += nums[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Optimal...

class NumArray
{
public:
    vector<int> prefix;
    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        prefix.resize(n + 1);

        prefix[0] = 0;
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */