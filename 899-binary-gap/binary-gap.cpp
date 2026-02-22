class Solution {
public:
    int binaryGap(int n) {
        int first = -1; 
        int second = -1;
        int pos = 0;
        int ans = 0;
        while(n)
        {
            if(n & 1)
            {
                second = first;
                first = pos;
                if(second != -1)
                ans = max(ans, (first - second));
            }
            n = n>>1;
            pos++;
        }
        return ans;
    }
};