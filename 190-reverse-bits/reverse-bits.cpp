class Solution {
public:
    int reverseBits(int n) {
        int ans =0;
        for(int i =0; i<32; i++)
        {
            int cur = n&1;
            cout<<cur;
            ans = ans|cur;
            if(i == 31) continue;
            ans = ans<<1;
            n = n>>1;
        }
        return ans;

    }
};