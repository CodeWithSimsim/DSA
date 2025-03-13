class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        multimap<int, int>mp;
        for(int i =0; i<n; i++)
        {
            mp.insert({arr[i], i});
        }

        int pre = mp.begin()->first;
        int rank =1;
        for(auto it: mp)
        {
            int num = it.first;
            int ind = it.second;
            if(num == pre)
            {
                ans[ind] = rank;
            }
            else
            {
                ans[ind] = rank+1;
                rank ++;
                pre = num;
            }
        }
        return ans;
    }
};