class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
        {
            return 0;
        }

        st.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // bfs...
        while (!q.empty())
        {
            string word = q.front().first;
            int counter = q.front().second;
            q.pop();

            if (word == endWord)
                return counter;

            for (int i = 0; i < word.size(); i++)
            {
                char originalChar = word[i]; // storing original char...
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, counter + 1});
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};