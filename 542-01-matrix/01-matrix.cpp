class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n= mat.size();
        int m = mat[0].size();

        vector<vector<int>>ans(n, vector<int>(m, 0));
        vector<vector<int>>vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>>que;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    que.push({{i, j}, 0});
                    vis[i][j] =1;
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        while(!que.empty())
        {
            int s = que.size();
            for(int i =0; i<s; i++)
            {
                auto top = que.front();
                que.pop();
                int row = top.first.first;
                int col = top.first.second;
                int dis = top.second;

                for(int d =0; d<4; d++)
                {
                    int nrow = row + dr[d];
                    int ncol = col + dc[d];

                    if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && mat[nrow][ncol] ==1 && vis[nrow][ncol] ==0)
                    {
                        vis[nrow][ncol] =1;
                        ans[nrow][ncol] = dis+1;
                        que.push({{nrow, ncol}, dis+1});
                    }
                }
            }
        }
        return ans;
    }
};