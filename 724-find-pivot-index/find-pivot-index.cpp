class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;

        // Calculate the total sum of the array.
        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Remove the current element from totalSum.
            // Now, totalSum represents the right sum.
            totalSum -= nums[i];

            // Check if left sum and right sum are equal.
            if (leftSum == totalSum) {
                return i;
            }

            // Add the current element to leftSum for the next iteration.
            leftSum += nums[i];
        }

        // No pivot index found.
        return -1;
    }
};