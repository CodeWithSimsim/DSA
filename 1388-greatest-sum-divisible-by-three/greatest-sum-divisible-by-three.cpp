class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>rem(n, 0);
        int rsum = 0;
        int cnt1=0, cnt2 =0;
        for(int i =0; i<n; i++)
        {
            rem[i] = nums[i]%3;
            rsum = rsum + rem[i];
            if(rem[i] == 1) cnt1++;
            if(rem[i] == 2) cnt2++;
        }

        int maxSum = accumulate(nums.begin(), nums.end(), 0);

        if(rsum %3 == 1)
        {
            int red1 =INT_MAX, red2 =INT_MAX;
            for(int i = 0; i<n; i++)
            {
                if(rem[i] == 1)
                {
                    red1 = nums[i];
                    break;
                }
                
            }
            if( cnt2 >= 2)
            {
                red2 =0;
                int cnt = 0;

                for(int i = 0; i<n; i++)
                {
                    if(rem[i] == 2)
                    {
                        red2 = red2 + nums[i];
                        cnt ++;
                    }
                    if(cnt ==2) break;
                }
            }

            int finalreduce = min(red1, red2);
            maxSum = maxSum - finalreduce;
            

        }

        if(rsum %3 == 2)
        {
            int red1 =INT_MAX, red2 =INT_MAX;
            for(int i = 0; i<n; i++)
            {
                if(rem[i] == 2)
                {
                    red2 = nums[i];
                    break;
                }
            }
            if( cnt1 >= 2)
            {
                red1 =0;
                int cnt = 0;

                for(int i = 0; i<n; i++)
                {
                    if(rem[i] == 1)
                    {
                        red1 = red1 + nums[i];
                        cnt ++;
                    }
                    if(cnt ==2) break;
                }
            }

            int finalreduce = min(red1, red2);
            maxSum = maxSum - finalreduce;
            

        }
        return maxSum;

    }
};