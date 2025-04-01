class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>que;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(i ==0 || i == n-1 || j ==0 || j== m-1 )
                {
                    if(grid[i][j] == 1)
                    {
                        que.push({i, j});
                        vis[i][j] =1;
                    }
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!que.empty())
        {
            auto top = que.front();
            que.pop();

            int row = top.first;
            int col = top.second;

            for(int i =0; i<4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && grid[nrow][ncol] == 1 && vis[nrow][ncol] ==0)
                {
                    que.push({nrow, ncol});
                    vis[nrow][ncol] =1;
                }
            }
        }
        int cnt =0;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j] == 1 && vis[i][j] ==0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};