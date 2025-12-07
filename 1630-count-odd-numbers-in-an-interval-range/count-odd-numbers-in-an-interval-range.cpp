class Solution {
public:
    int countOdds(int low, int high) {
        int cnt =0;
        if(low %2)
        {
            cnt++;
            low++;
        }
        if(high %2)
        {
            cnt++;
            high--;
        }
        cnt = cnt+ (high - low)/2;
        return cnt;
    }
};