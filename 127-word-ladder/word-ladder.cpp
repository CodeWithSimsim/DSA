class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> que;
        que.push({beginWord, 1});  // start from 1 because beginWord counts

        while(!que.empty()) {
            auto [curStr, attemp] = que.front();
            que.pop();

            if(curStr == endWord) return attemp;

            for(int i = 0; i < curStr.length(); i++) {
                char original = curStr[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    curStr[i] = ch;
                    if(st.find(curStr) != st.end()) {
                        que.push({curStr, attemp + 1});
                        st.erase(curStr);
                    }
                }
                curStr[i] = original;
            }
        }

        return 0;  // if endWord is not reachable
    }
};
