// Time complexity -> O(m * nlogn)
// Space complexity -> O(mn)

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> ans; // Define a Hash Map

        for (string &s : strs)
        { // Iterate Through Each Word in the Input
            string key = s;
            sort(key.begin(), key.end()); // sorting each key
            ans[key].push_back(s);
        }

        vector<vector<string>> result; // set to vector
        for (auto &entry : ans)
        {
            result.push_back(entry.second); // takes only vector
        }

        return result;
    }
};
// unordered map created from the first for loop...
// {
//     "aet": ["eat", "tea", "ate"],
//     "ant": ["tan", "nat"],
//     "abt": ["bat"]
// }
