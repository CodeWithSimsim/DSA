class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre = -1;
        int i=0;
        while(n)
        {
            int cur = n & 1;
            if(cur == pre) return false;
            pre = cur;
            n = n>>1;
        }
        return true;
    }
};