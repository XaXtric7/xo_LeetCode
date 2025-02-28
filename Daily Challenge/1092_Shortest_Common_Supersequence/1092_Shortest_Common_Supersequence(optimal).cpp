// Shortest Common Supersequence
// common guys should be taken once[common guy? it will be the LCS of both s1 and s2 -- LCS={Longest common sequence}]
// "brute" and  "groot"
// "brutegroot"  could this be the SCS ? no. why >>>> len = 10.
// "bgruoote" would be the SCS....  len = 8

// ALGORITHM
// 1. Initialize lengths: Compute str1Length and str2Length.
// 2. Set up DP storage: Initialize prevRow of size str2Length + 1 to store prefixes of str2.
// 3. Iterate over str1:
//      Create currRow to store results for the current row.
//      Set currRow[0] as the prefix of str1.
// 4. Iterate over str2:
//      If str1[row - 1] == str2[col - 1]: Append the common character to prevRow[col - 1] → currRow[col].
//      Else: Choose the shorter supersequence between prevRow[col] (excluding str1[row - 1]) and currRow[col - 1] (excluding str2[col - 1]).
// 5. Update prevRow for the next row iteration.
// 6. Return prevRow[str2Length], which contains the shortest common supersequence.

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int str1Length = str1.length();
        int str2Length = str2.length();

        // Initialize the first row (when str1 is empty, the supersequence is
        // str2's prefix)
        vector<string> prevRow(str2Length + 1);
        for (int col = 0; col <= str2Length; col++)
        {
            prevRow[col] = str2.substr(0, col);
        }

        // Fill the DP table row by row
        for (int row = 1; row <= str1Length; row++)
        {
            // Initialize the first column (when str2 is empty, the
            // supersequence is str1's prefix)
            vector<string> currRow(str2Length + 1);
            currRow[0] = str1.substr(0, row);

            for (int col = 1; col <= str2Length; col++)
            {
                // If characters match, extend the supersequence from the
                // diagonal value
                if (str1[row - 1] == str2[col - 1])
                {
                    currRow[col] = prevRow[col - 1] + str1[row - 1];
                }
                else
                {
                    // If characters do not match, choose the shorter
                    // supersequence From previous row (exclude current str1
                    // char)
                    string pickS1 = prevRow[col];
                    // From previous column (exclude current str2 char)
                    string pickS2 = currRow[col - 1];

                    currRow[col] = (pickS1.length() < pickS2.length())
                                       ? pickS1 + str1[row - 1]
                                       : pickS2 + str2[col - 1];
                }
            }
            // Move to the next row (update previous row reference)
            prevRow = currRow;
        }

        // Return the shortest common supersequence from the last cell
        return prevRow[str2Length];
    }
};