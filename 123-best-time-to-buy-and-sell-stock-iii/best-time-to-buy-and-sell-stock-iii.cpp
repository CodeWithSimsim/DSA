class Solution {
public:
    int helper(int ind, int state, int cnt, vector<int>& prices, vector<vector<vector<int>>> & dp)
    {
        if(ind == prices.size() || cnt == 0) return 0;

        if(dp[ind][state][cnt] != -1) return dp[ind][state][cnt];

        int profit =0;
        if(state ==0)
        {
            profit = max(helper(ind+1, 0, cnt, prices, dp), -prices[ind] + helper(ind+1, 1, cnt, prices, dp));
        }
        else
        {
            profit = max(helper(ind+1, 1, cnt, prices, dp), +prices[ind] + helper(ind+1, 0, cnt-1, prices, dp));
        }
        return dp[ind][state][cnt] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <=1) return 0;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 0, 2, prices, dp);
    }
};