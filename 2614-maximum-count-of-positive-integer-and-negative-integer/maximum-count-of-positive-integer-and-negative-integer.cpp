class Solution {
public:
    int cntP(int left, int right, vector<int>& nums)
    {
        int n = nums.size();
        int ind = n;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] > 0)
            {
                ind = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ind;
    }

    int cntN(int left, int right, vector<int>& nums)
    {
        int ind = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] < 0)
            {
                ind = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return ind;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int indP = cntP(0, n-1, nums);
        int indN = cntN(0, n-1, nums);
        if(indP == n && indN == -1) return 0;
        if(indP == n) return indN+1;
        if(indN == n) return n- indP;
        int maxCnt = max(n-indP, indN+1);
        return maxCnt;
    }
};