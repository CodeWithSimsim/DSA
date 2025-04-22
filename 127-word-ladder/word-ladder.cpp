class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        set<string>st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>>que;
        que.push({beginWord, 1});
        int cnt =0;
        while(!que.empty())
        {
            auto [curWord, step] = que.front();
            que.pop();
            if(curWord == endWord)
            {
                cnt = step;
                break;
            }
            for(int i =0; i<n; i++)
            {
                char original =  curWord[i];
                for(char ch = 'a'; ch<='z'; ch++)
                {
                    curWord[i] = ch;
                    if(st.find(curWord) != st.end())
                    {
                        st.erase(curWord);
                        que.push({curWord, step+1});
                    }
                    curWord[i] = original;
                }
            }
        }
        return cnt;
    }
};
