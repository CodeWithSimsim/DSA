class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int cntN =0, cntP =0;
        for(int i =0; i<n; i++)
        {
            if(nums[i] < 0) cntN++;
            if(nums[i] > 0) cntP++;
        }
        return max(cntN, cntP);
    }
};