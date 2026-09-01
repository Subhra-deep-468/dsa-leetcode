class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // Stores the smallest possible tail of an
        // increasing subsequence of each length.
        vector<int> lis;

        for (int x : nums) {

            // Find the first element >= x
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end()) {
                // No element >= x
                // Extend the longest increasing subsequence
                lis.push_back(x);
            } else {
                // Replace the first element >= x
                // to keep the tail as small as possible
                *it = x;
            }
        }

        // Size of lis is the length of the LIS
        return lis.size();
    }
};