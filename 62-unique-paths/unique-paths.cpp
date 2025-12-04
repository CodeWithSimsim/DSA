class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& dp)
    {
        if(i <0 || j <0) return 0;
        if(i ==0 && j ==0) return dp[0][0] = 1;
        if(dp[i][j] != -1) return dp[i][j];
        int left = helper(i, j-1, dp);
        int up = helper(i-1, j, dp);

        return dp[i][j] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = helper(m-1, n-1, dp);

        for(int i = 0; i<m; i++)
        {
            dp[i][0] =1;
        }
        for(int j =0; j<n; j++)
        {
            dp[0][j] =1;
        }

        for(int i =1; i<m; i++)
        {
            for(int j =1; j<n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        //return ans;
    }
};