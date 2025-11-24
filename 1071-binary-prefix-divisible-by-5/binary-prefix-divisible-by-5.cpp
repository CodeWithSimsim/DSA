class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int no = 0;
        vector<bool>ans(n, false);
        for(int i =0; i<n; i++)
        {
            int cur = (nums[i] == 1 ? 1 : 0);
            no = (no*2) + cur;
            if(no%5 == 0) ans[i] = true;
            no = no%100;
        }
        return ans;
    }
};