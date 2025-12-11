class Solution {
public:

    int helper(int ind, int preb, vector<int>& prices)
    {
        if(ind >= prices.size()) return 0;
        int profit = 0;
        if(prices[ind] > preb)
        {
            profit = max(prices[ind] - preb + helper(ind+1, prices[ind], prices), helper(ind+1, preb, prices));
        }
        else
        {
            profit = helper(ind+1, prices[ind], prices);
        }

        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n ==1) return 0;
        //return helper(1, prices[0], prices);

        int maxp = 0;
        int pre = prices[0];
        for(int i =1; i<n; i++)
        {
            if(prices[i] > pre)
            {
                maxp = maxp + (prices[i] - pre);
            }
            pre = prices[i];
        }
        return maxp;
    }

};