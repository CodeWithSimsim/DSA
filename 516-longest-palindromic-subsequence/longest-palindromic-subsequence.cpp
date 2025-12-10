class Solution {
public:

    int helper(int left, int right, string &s, vector<vector<int>>& dp)
    {
        if(left == right) return 1;
        if(left > right) return 0;

        if(dp[left][right] != -1) return dp[left][right];

        if(s[left] == s[right])
        {
            return dp[left][right] = 2 + helper(left+1, right-1, s, dp);
        }
        else
        {
            return dp[left][right] = max(helper(left+1, right, s, dp), helper(left, right-1, s, dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return helper(0, n-1, s, dp);

    }
};