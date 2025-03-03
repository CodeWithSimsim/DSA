class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int>ms;
        for(int i =0; i<k-1; i++)
        {
            ms.insert(nums[i]);
        }
        int start = 0;
        vector<int>ans;

        for(int i = k-1; i<n; i++)
        {
            ms.insert(nums[i]);
            int curMax = *ms.rbegin();
            ans.push_back(curMax);
            
            auto it = ms.find(nums[start]);
            if (it != ms.end()) {
                ms.erase(it);
            }
            start++;
        }
        return ans;
    }
};