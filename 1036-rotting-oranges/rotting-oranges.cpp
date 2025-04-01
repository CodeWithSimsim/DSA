class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>>que;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    vis[i][j] =1;
                }
                else if(grid[i][j] == 2)
                {
                    que.push({i, j});
                    vis[i][j] =2;
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1,  0, -1};

        int cnt = 0;
        while(!que.empty())
        {
            int s = que.size();
            bool check = false;
            for(int i =0; i<s; i++)
            {
                auto top = que.front();
                que.pop();
                int crow = top.first;
                int ccol = top.second;

                // now move in all four direction up, left, right, down
                
                for(int i =0; i<4; i++)
                {
                    int nrow = crow + dr[i];
                    int ncol = ccol + dc[i];

                    if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && vis[nrow][ncol] == 1)
                    {
                        vis[nrow][ncol] =2;
                        que.push({nrow, ncol});
                        check = true;
                    }
                }
            }
            if(check) cnt++;
        }

        bool isPossible = true;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(vis[i][j] == 1)
                {
                    isPossible = false;
                    break;
                }
            }
        }
        return ((isPossible) ? cnt : -1 );
    }
};