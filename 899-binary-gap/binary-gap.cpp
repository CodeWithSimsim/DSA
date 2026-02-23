class Solution {
public:
    int binaryGap(int n) {
        int pre = -1; 
        
        int cur = 0;
        int ans = 0;
        while(n)
        {
            if(n & 1)
            {
                if(pre != -1)
                ans = max(ans, (cur - pre));
                pre = cur;
            }
            n = n>>1;
            cur++;
        }
        return ans;
    }
};