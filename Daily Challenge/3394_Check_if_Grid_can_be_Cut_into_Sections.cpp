class Solution
{
private:
    bool canCut(vector<vector<int>> &rectangles, int axis)
    {
        sort(rectangles.begin(), rectangles.end(),
             [axis](vector<int> &a, vector<int> &b)
             { return a[axis] < b[axis]; });

        int cuts = 0, previousEnd = -1;

        for (auto &rect : rectangles)
        {
            int start = rect[axis], end = rect[axis + 2];

            if (start >= previousEnd)
                cuts++;
            previousEnd = max(previousEnd, end);
            if (cuts >= 3)
                return true;
        }

        return false;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        return canCut(rectangles, 0) || canCut(rectangles, 1);
    }
};