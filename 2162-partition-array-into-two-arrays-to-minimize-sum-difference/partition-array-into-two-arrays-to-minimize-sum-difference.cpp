class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>>subSet1(n+1), subSet2(n+1);

        for(int i =0; i<(1<<n); i++)
        {
            int cnt =0, sum1 =0, sum2=0;
            for(int j =0; j<n; j++)
            {
                if(i & (1<<j))
                {
                    cnt++;
                    sum1 = sum1 + nums[j];
                    sum2 = sum2 + nums[j+n];
                }
            }
            subSet1[cnt].push_back(sum1);
            subSet2[cnt].push_back(sum2);
        }

        for(int i =0; i<=n; i++)
        {
            sort(subSet2[i].begin(), subSet2[i].end());
        }
        int minDif = INT_MAX;
        for(int i =0; i<=n; i++)
        {
            for(int j =0; j<subSet1[i].size(); j++)
            {
                int a = subSet1[i][j];
                int target = totalSum/2 - a;
                auto it = lower_bound(subSet2[n-i].begin(), subSet2[n-i].end(), target);

                if(it != subSet2[n-i].end())
                {
                    minDif = min (minDif, abs(totalSum -2*(a + *(it))));
                }
                
                if(it != subSet2[n-i].begin())
                {
                    it--;
                    minDif = min (minDif, abs(totalSum -2*(a + *(it))));
                }
            }
        }
        return minDif;
        
    }
};