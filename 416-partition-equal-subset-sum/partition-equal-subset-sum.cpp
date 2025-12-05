class Solution {
public:

    bool check(int ind, int hsm, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(hsm ==0) return true;
        if(ind < 0 || hsm < 0) return false;

        if(dp[ind][hsm] != -1) return dp[ind][hsm];

        bool select = check(ind -1, hsm-nums[ind], nums, dp);
        bool notSelect = check(ind-1, hsm, nums, dp);

        return dp[ind][hsm] = (select || notSelect);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum %2 != 0) return false;
        
        vector<vector<int>>dp(n, vector<int>(sum/2 +1, -1));

        bool ans = check(n-1, sum/2, nums, dp);

        return ans;

    }
};