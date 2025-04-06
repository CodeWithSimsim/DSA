class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>>que;
       
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j] ==2)
                {
                    que.push({{i, j}, 0});
                    grid[i][j] =2;
                }
            }
        }

        int maxDay =0;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        while(!que.empty())
        {
            auto top = que.front();
            que.pop();
            int row = top.first.first;
            int col = top.first.second;
            int day = top.second;

            maxDay = max(maxDay, day);
            for(int i =0; i<4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 && nrow <n && ncol >=0 && ncol <m && grid[nrow][ncol] ==1 )
                {
                    que.push({{nrow, ncol}, day+1});
                    grid[nrow][ncol] =2;
                }
            }
        }

        bool isPossible = true;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(grid[i][j] ==1)
                {
                    isPossible = false;
                    break;
                }
            }
        }
        return (!isPossible ? -1 : maxDay);
    }
};