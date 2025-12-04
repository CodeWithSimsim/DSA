class Solution {
public:

    int minSum(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(row <0 || col <0) return INT_MAX;
        if(row == 0 && col ==0) return dp[0][0] = grid[0][0];

        if(dp[row][col] != -1) return dp[row][col];

        int left = minSum(row, col-1, grid, dp);
        int right = minSum(row-1, col, grid, dp);

        return dp[row][col] = grid[row][col] + min(left, right);

    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        int sum = minSum(n-1, m-1, grid, dp);
        return sum;
    }
};