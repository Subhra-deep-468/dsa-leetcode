class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // A mountain needs at least 3 elements.
        if (n < 3) {
            return 0;
        }

        // Traverse the array and look for peaks.
        for (int i = 1; i < n - 1; i++) {

            // Check if nums[i] is a peak.
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {

                int left = i;
                int right = i;

                // Move left while the sequence is strictly increasing.
                while (left > 0 && nums[left] > nums[left - 1]) {
                    left--;
                }

                // Move right while the sequence is strictly decreasing.
                while (right < n - 1 && nums[right] > nums[right + 1]) {
                    right++;
                }

                // Calculate the length of the mountain.
                int length = right - left + 1;

                // Update the maximum length found.
                ans = max(ans, length);
            }
        }

        return ans;
    }
};