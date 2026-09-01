class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                // Minimum is on the left side
                right = mid;
            }
            else if (nums[mid] > nums[right]) {
                // Minimum is on the right side
                left = mid + 1;
            }
            else {
                // nums[mid] == nums[right]
                // We cannot decide, so remove duplicate
                right--;
            }
        }

        return nums[left];
    }
};