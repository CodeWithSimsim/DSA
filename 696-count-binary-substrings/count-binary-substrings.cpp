class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        char cursection = s[0];
        int curCnt =1;
        int preCnt =0;
        int ans =0;
        for(int i =1; i<n; i++)
        {
            if(s[i] != cursection)
            {
                preCnt = curCnt;
                curCnt = 1;
                cursection = s[i];
            }
            else
            {
                curCnt++; 
            }
            if(curCnt <= preCnt)
            {
                ans++;
            }
        }
        return ans;
    }
};