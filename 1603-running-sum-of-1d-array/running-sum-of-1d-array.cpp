class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int preSum =0;
        for(int i =0; i<n; i++)
        {
            preSum += nums[i];
            ans.push_back(preSum);
        }
        return ans;
    }
};