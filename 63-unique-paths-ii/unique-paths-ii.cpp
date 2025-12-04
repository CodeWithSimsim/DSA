class Solution {
public:

    int findPath(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(m < 0 || n < 0) return 0;
        if(grid[m][n] == 1) return 0;
        if(m ==0 && n ==0) return dp[0][0] = 1;

        if(dp[m][n] != -1) return dp[m][n];

        int left = findPath(m, n-1, grid, dp);
        int up = findPath(m-1, n, grid, dp);
        return dp[m][n] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row, vector<int>(col, -1));
        int totalPath = findPath(row-1, col-1, grid, dp);

        return totalPath;

    }
};