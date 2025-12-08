class Solution {
public:

    int helper(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(amount ==0) return 1;
        if(ind < 0) return 0;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int select = 0;
        if( coins[ind] <= amount)
        select = helper(ind, amount-coins[ind], coins, dp);
        int notSelect = helper(ind-1, amount, coins, dp);
        return dp[ind][amount] = select + notSelect;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return helper(n-1, amount, coins, dp);

    }
};