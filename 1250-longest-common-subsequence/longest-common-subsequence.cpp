class Solution {
public:

    int helper(int ind1, int ind2, string &text1, string &text2, vector<vector<int>>& dp)
    {
        if(ind1 <0 || ind2 <0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int match =0;
        if(text1[ind1] == text2[ind2])
        {
            match = 1 + helper(ind1-1, ind2-1, text1, text2, dp);
        }
        int notMatch = max(helper(ind1-1, ind2, text1, text2, dp), helper(ind1, ind2-1, text1, text2, dp));
        return dp[ind1][ind2] = max(match, notMatch);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1= text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        //return helper(n1-1, n2-1, text1, text2, dp);

        vector<vector<int>>dp2(n1, vector<int>(n2, 0));
        for(int i =0; i<n1; i++)
        {
            for(int j =0; j<n2; j++)
            {
                if(text1[i] == text2[j])
                {
                    int pre = 0;
                    if(i-1 >=0 && j-1 >=0) pre = dp[i-1][j-1];
                    dp[i][j] = 1 + pre;

                }
                else 
                {
                    int pr = 0, pc =0;
                    if(i-1 >=0) pr = dp[i-1][j];
                    if(j-1 >=0) pc = dp[i][j-1];
                    dp[i][j] = max(pr, pc);
                }
            }
        }
        return dp[n1-1][n2-1];
    }
};