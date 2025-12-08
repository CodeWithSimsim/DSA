class Solution {
public:

    int helper(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(amount ==0) return 0;
        if(ind <0 || amount < 0) return 1e9;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int select = helper(ind, amount-coins[ind], coins, dp);
        if(select != 1e9)
        {
            select = 1+select;
        }
        int notSelect = helper(ind-1, amount, coins, dp);
        return dp[ind][amount] = min(select, notSelect);

    }
    int coinChange(vector<int>& coins, int amount) {
          int n = coins.size();
          vector<vector<int>>dp(n, vector<int>(amount+1, -1));
          int ans = helper(n-1, amount, coins, dp);
          if(ans == 1e9) return -1;
          return ans;
    }
};