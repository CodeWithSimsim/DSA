class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        map<vector<int>, int>map;

        for(int i =0; i<n; i++)
        {
            sort(dominoes[i].begin(), dominoes[i].end());
            map[dominoes[i]]++;
        }
        int ans = 0;
        for(auto it : map)
        {
            if(it.second >=2)
            {
                int cnt = it.second;
                int pair = (cnt * (cnt-1))/2;
                ans = ans + pair;
            }
        }
        return ans;
    }
};