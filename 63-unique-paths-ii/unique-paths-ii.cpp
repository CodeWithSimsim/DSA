class Solution {
public:

/*
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

*/
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dp(row, vector<int>(col, -1));
        //int totalPath = findPath(row-1, col-1, grid, dp);

        vector<vector<int>>tab(row, vector<int>(col, 0));
        

        for(int i =0; i<row; i++)
        {
            for(int j =0; j<col; j++)
            {
                if(grid[i][j] ==1)
                {
                    tab[i][j] =0;
                    continue;
                }
                if(i ==0 && j==0)
                {
                    tab[0][0] =1;
                    continue;
                }
                
                int left =0;
                int up =0;
                if(j-1 >=0) left = tab[i][j-1];
                if(i-1 >=0) up = tab[i-1][j];

                tab[i][j] = left + up;
                
            }
        }

        //return totalPath;
        return tab[row-1][col-1];

    }
};