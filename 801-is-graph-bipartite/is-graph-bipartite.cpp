class Solution {
public:
    
    bool dfs(int node, int color, vector<int>& vis, vector<vector<int>>&graph)
    {
        vis[node] = color;
        for(auto it : graph[node])
        {
            if(vis[it] == -1)
            {
                if(dfs(it, !color, vis, graph)== false) return false;
            }
            else
            {
                if(vis[it] == color) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v, -1);
        for(int i=0; i<v; i++)
        {
            if(vis[i] == -1)
            {
                if(dfs(i, 0, vis, graph) == false) return false;
            }
        }
        return true;
    }
};