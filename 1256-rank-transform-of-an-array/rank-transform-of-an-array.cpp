class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;  // Copy the original array
        sort(sortedArr.begin(), sortedArr.end());  // Sort the array

        map<int, int> rankMap;
        int rank = 1;

        // Assign ranks to unique elements
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) { // First occurrence of num
                rankMap[num] = rank++;
            }
        }

        // Replace elements in the original array with their ranks
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = rankMap[arr[i]];
        }
        
        return ans;
    }
};
