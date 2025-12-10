class Solution {
public:

    int helper(int left, int right, string &s, vector<vector<int>>& dp)
    {
        if(left >= right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int minStep = 1e9;
        if(s[left] == s[right])
        {
            minStep = helper(left+1, right-1, s, dp);
        }
        else
        {
            minStep = 1 + min(helper(left+1, right, s, dp), helper(left, right-1, s, dp));
        }
        return dp[left][right] = minStep;
    }

    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return helper(0, n-1, s, dp);
    }
};