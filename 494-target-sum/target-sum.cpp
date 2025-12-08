class Solution {
public:
    int countWays(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind <0 && sum == 0) return 1;
        if (ind < 0) return 0;

        if (dp[ind][sum] != -1) return dp[ind][sum];

        int take = 0;
        if (nums[ind] <= sum)
            take = countWays(ind - 1, sum - nums[ind], nums, dp);

        int notTake = countWays(ind - 1, sum, nums, dp);

        return dp[ind][sum] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Impossible cases
        if (abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2 != 0) return 0;

        int S1 = (totalSum + target) / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(S1 + 1, -1));
        return countWays(nums.size() - 1, S1, nums, dp);
    }
};
