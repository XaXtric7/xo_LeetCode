// Time Complexit -> O(n^2)
// Space Complexity -> O(n^2)

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int total = n * n; // total elements in the given array
        vector<int> grid2;
        unordered_set<int> seen; // To track
        int repeated, missing;

        // from a grid to a single 1D vector for ease in calculation
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num = grid[i][j];
                if (seen.count(num))
                {
                    repeated = num; // repeated number
                }
                seen.insert(num);
                grid2.push_back(num);
            }
        }

        // missing number
        for (int i = 1; i <= total; i++)
        {
            if (!seen.count(i))
            {
                missing = i;
                break;
            }
        }

        return {repeated, missing};
    }
};