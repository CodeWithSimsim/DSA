class Solution {
public:

    int helper(int ind1, int ind2, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if(ind1 <0 && ind2 <0) return 0;
        if(ind1 <0) return ind2+1;
        if(ind2 <0) return ind1+1;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int mindis = INT_MAX;

        if(word1[ind1] == word2[ind2])
        {
            mindis = helper(ind1-1, ind2-1, word1, word2, dp);
        }
        else
        {
            int replace = 1 + helper(ind1-1, ind2-1, word1, word2, dp);
            int erase = 1 + helper(ind1-1, ind2, word1, word2, dp);
            int insert = 1 + helper(ind1, ind2-1, word1, word2, dp);

            mindis = min(replace, min(erase, insert));
        }

        return dp[ind1][ind2] = mindis;
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return helper(n1-1, n2-1, word1, word2, dp);

    }
};