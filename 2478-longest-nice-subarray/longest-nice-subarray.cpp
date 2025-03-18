class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int sind = 0, bitmask = 0, maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Shrink the window if there's a conflict
            while ((bitmask & nums[i]) != 0) {
                bitmask ^= nums[sind]; // Remove nums[sind] from bitmask
                sind++;
            }
            bitmask |= nums[i]; // Add nums[i] to bitmask
            maxlen = max(maxlen, i - sind + 1);
        }
        return maxlen;
    }
};
