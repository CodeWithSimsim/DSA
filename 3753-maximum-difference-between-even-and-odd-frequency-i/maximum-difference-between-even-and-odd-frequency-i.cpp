
class Solution {
public:
    int maxDifference(string s) {
        int cnt[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
        }
        int odd =0, even = INT_MAX;
        for(int i =0; i<26; i++)
        {
            if(cnt[i] > 0)
            {
                if(cnt[i]%2 ==0)
                {
                    even = min (even, cnt[i]);
                }
                else
                {
                    odd = max(odd, cnt[i]);
                }
            }
        }
        return (odd - even);
    }
};