class Solution {
public:
    bool isOdd(int x)
    {
        if(x%2 != 0)return true;
        return false;
    }
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i =1; i<arr.size()-1; i++)
        {
            if(isOdd(arr[i-1]) && isOdd(arr[i]) && isOdd(arr[i+1])) return true;
        }
        return false;
    }
};