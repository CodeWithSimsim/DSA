class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        int mfreq = 0;
        for(auto it : nums)
        {
            mp[it] ++;
            mfreq = max(mfreq, mp[it]);
        }
        int ans =0;
        for(auto it : mp)
        {
            if(it.second == mfreq)
            {
                ans = ans+ mfreq;
            }
        }
        return ans;
    }
};