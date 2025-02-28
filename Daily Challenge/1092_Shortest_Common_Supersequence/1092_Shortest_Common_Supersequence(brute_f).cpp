// Shortest Common Supersequence
// common guys should be taken once[common guy? it will be the LCS of both s1 and s2 -- LCS={Longest common sequence}]
// "brute" and  "groot"
// "brutegroot"  could this be the SCS ? no. why >>>> len = 10.
// "bgruoote" would be the SCS....  len = 8

// ALGORITHM
// 1. Base Cases:
//      If both str1 and str2 are empty → return "".
//      If str1 is empty → return str2.
//      If str2 is empty → return str1.
// 2. Matching Characters:
//      If str1[0] == str2[0]:
//          Append the common character to the result of a recursive call with str1[1:] and str2[1:].
// 3. Non-Matching Characters:
//      Option 1: Append str1[0] and recurse with str1[1:] and str2.
//      Option 2: Append str2[0] and recurse with str1 and str2[1:].
//      Return the shorter result between both options.

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        // Base case: both strings are empty
        if (str1.empty() && str2.empty())
        {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.empty())
        {
            return str2;
        }

        if (str2.empty())
        {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1[0] == str2[0])
        {
            return str1[0] +
                   shortestCommonSupersequence(str1.substr(1), str2.substr(1));
        }
        else
        {
            // Try both options: picking from str1 or str2, and choose the
            // shorter one
            string pickStr1 =
                str1[0] + shortestCommonSupersequence(str1.substr(1), str2);
            string pickStr2 =
                str2[0] + shortestCommonSupersequence(str1, str2.substr(1));

            return (pickStr1.length() < pickStr2.length()) ? pickStr1
                                                           : pickStr2;
        }
    }
};