class Solution {
public:
    int helper(int n)
    {
        int cnt =0; 
        while(n)
        {
            
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int ans =0;
        unordered_set<int>st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for(int i = left; i<=right; i++)
        {
            int setBit = helper(i);
            if(st.find(setBit) != st.end()) ans++;
        }
        return ans;
    }
};