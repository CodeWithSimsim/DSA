class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        set<string>st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>>que;
        que.push({beginWord, 1});

        while(!que.empty())
        {
            string str = que.front().first;
            int len = que.front().second;
            que.pop();

            if(str == endWord) return len;
            for(int i =0;i<n; i++)
            {

                char oc = str[i];
                for(char ch = 'a'; ch <='z'; ch++)
                {
                    if (ch == oc) continue;
                    str[i] = ch;
                    if(st.find(str) != st.end())
                    {
                        que.push({str, len+1});
                        st.erase(str);
                    }
                }
                str[i] = oc;
            }
        }
        return 0;
    }
};