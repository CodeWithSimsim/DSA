class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        unordered_set<string>st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>>que;
        que.push({beginWord, 1});
        st.erase(beginWord);

        while(!que.empty())
        {
            auto [word, op] = que.front();
            que.pop();

            if(word == endWord) return op;
            for(int i =0; i<n; i++)
            {
                char cur = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    auto it = st.find(word);
                    if(it != st.end())
                    {
                        que.push({word, op+1});
                        st.erase(word);
                    }
                }
                word[i] = cur;
            }
        }
        return 0;
        
    }
};
