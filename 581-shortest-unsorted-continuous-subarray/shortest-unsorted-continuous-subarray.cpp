class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = -1;
        int right = -1;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        // Find right boundary
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            if (nums[i] < maxi) {
                right = i;
            }
        }

        // Find left boundary
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);

            if (nums[i] > mini) {
                left = i;
            }
        }

        if (left == -1)
            return 0;

        return right - left + 1;
    }
};