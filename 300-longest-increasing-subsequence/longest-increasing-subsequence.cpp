class Solution {
public:
    int helper(int ind, int pre, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) return 0;

        // shift pre by +1 (so -1 -> 0)
        if (dp[ind][pre + 1] != -1) 
            return dp[ind][pre + 1];

        int take = 0;
        if (pre == -1 || nums[ind] > nums[pre]) {
            take = 1 + helper(ind + 1, ind, nums, dp);
        }

        int notTake = helper(ind + 1, pre, nums, dp);

        return dp[ind][pre + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // dp[ind][pre+1]

        return helper(0, -1, nums, dp);
    }
};
