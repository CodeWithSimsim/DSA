class Solution {
public:

    int findMin(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(col <0 || col >= triangle[row].size()) return INT_MAX;
        if(row ==0 && col == 0) return dp[0][0] = triangle[0][0];

        if(dp[row][col] != -1) return dp[row][col];
        int si = findMin(row-1, col, triangle, dp);
        int si1 = findMin(row-1, col-1, triangle, dp);

        return dp[row][col] = triangle[row][col] + min(si, si1);
    }   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int c =0; c<triangle[n-1].size(); c++)
        {
            int minc = findMin(n-1, c, triangle, dp);
            ans = min(ans, minc);
        }
        return ans;
    }
};