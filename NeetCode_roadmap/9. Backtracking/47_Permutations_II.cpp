class Solution {
private:
    void permutations(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i = index; i < nums.size(); i++){
            if(used.count(nums[i])){
                continue;
            }
            used.insert(nums[i]);

            swap(nums[index], nums[i]);
            permutations(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(0, nums, ans);
        return ans;
    }
};