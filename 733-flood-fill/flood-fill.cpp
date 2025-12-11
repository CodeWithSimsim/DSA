class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == color) return image;
        queue<pair<int, int>>que;
        int start = image[sr][sc];
        image[sr][sc] = color;
        que.push({sr, sc});
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!que.empty())
        {
            auto [r, c] = que.front();
            que.pop();
            for(int i =0; i<4; i++)
            {
                int nr = r +dr[i];
                int nc = c + dc[i];
                if(nr >=0 && nr <n && nc >=0 && nc <m && image[nr][nc] == start)
                {
                    image[nr][nc] = color;
                    que.push({nr, nc});
                }
            }
        }
        return image;
    }
};