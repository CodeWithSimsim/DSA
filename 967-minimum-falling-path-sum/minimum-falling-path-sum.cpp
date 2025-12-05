class Solution {
public:

    int pathSum(int row, int col,int size,  vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(col <0 || col >= size) return INT_MAX;
        if(row == 0) return dp[row][col] = matrix[row][col];

        if(dp[row][col] != -1) return dp[row][col];

        int left = pathSum(row-1, col-1, size, matrix, dp);
        int up = pathSum(row-1, col, size, matrix, dp);
        int right = pathSum(row-1, col+1, size, matrix, dp);

        return dp[row][col] = matrix[row][col] + min(left, min(up, right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        /*
        int ans = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));

        for(int i = 0; i<n; i++)
        {
            ans = min(ans, pathSum(n-1, i, n, matrix, dp));
        }
        return ans;

        */
        vector<vector<int>>tab(n, vector<int>(n, -1));

        for(int i=0; i<n; i++)
        {
            tab[0][i] = matrix[0][i];
        }

        int minS = 1e9;
        for(int i =1; i<n; i++)
        {
            int left = 1e9, up = 1e9, right = 1e9;
            for(int j =0; j<n; j++)
            {
                if(j-1 >=0) left = tab[i-1][j-1];
                up = tab[i-1][j];
                if(j+1 <n) right = tab[i-1][j+1];

                tab[i][j] = matrix[i][j] + min(left, min(right, up));
            }
        }

        for(int i =0; i<n; i++)
        {
            minS = min(minS, tab[n-1][i]);
        }
        return minS;
    }
};