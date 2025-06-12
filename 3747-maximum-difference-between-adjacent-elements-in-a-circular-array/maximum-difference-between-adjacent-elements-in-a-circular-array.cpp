class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int dif = 0;
        for(int i =0; i<n-1; i++)
        {
            int curDif = abs(nums[i] - nums[i+1]);
            dif = max(dif, curDif);
        }
        dif = max(dif, abs(nums[0] - nums[n-1]));
        return dif;
    }
};