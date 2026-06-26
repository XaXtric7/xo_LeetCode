class Solution
{
private:
    void combinations(int start, int n, int k, vector<int> comb, vector<vector<int>> &ans)
    {
        if (comb.size() == k)
        {
            ans.push_back(comb);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            // pick...
            comb.push_back(i);

            combinations(i + 1, n, k, comb, ans);

            // not pick...
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> comb;
        vector<vector<int>> ans;
        combinations(1, n, k, comb, ans);
        return ans;
    }
};