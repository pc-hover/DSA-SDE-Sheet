#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> Q;
        Q.push({beginWord, 1});
        // using set search and delete tc is O(1)
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        // length of wordList
        while (!Q.empty())
        {
            string word = Q.front().first;
            int steps = Q.front().second;
            Q.pop();
            if (word == endWord)
            {
                return steps;
            }

            // tc = word.length * 26 *log N log for set
            for (int i = 0; i < word.size(); i++)
            {
                // word =play
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    // alay
                    // blay
                    // clay ...zlay
                    word[i] = ch;
                    if (st.find(word) != st.end())

                    {
                        st.erase(word);
                        Q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}