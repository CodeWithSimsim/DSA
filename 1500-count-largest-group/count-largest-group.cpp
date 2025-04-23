class Solution {
public:
    int helper(int n)
    {
        int sum =0;
        while(n>0)
        {
            sum = sum + n%10;
            n = n/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int, int>mp;
        for(int i =1; i<=n; i++)
        {
            int digiSum = helper(i);
            mp[digiSum]++;
        }
        int size =0;
        int cnt = 0;
        for(auto it : mp)
        {
            if(it.second > size)
            {
                size = it.second;
                cnt =1;
            }
            else if(it.second == size)
            {
                cnt++;
            }
        }
        return cnt;
    }
};