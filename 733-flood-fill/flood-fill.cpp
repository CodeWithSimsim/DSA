class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>>que;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        que.push({sr, sc});
        vis[sr][sc] =1;
        int stColor = image[sr][sc];
        image[sr][sc] = color;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!que.empty())
        {
            auto top = que.front();
            que.pop();
            int crow = top.first;
            int ccol = top.second;

            for(int i =0; i<4; i++)
            {
                int nrow = crow + dr[i];
                int ncol = ccol + dc[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol <m && image[nrow][ncol] == stColor && vis[nrow][ncol] == 0)
                {
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    que.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};