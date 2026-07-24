class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int low = 0;
        int high = arr.size() - k;

        // Binary search on the starting index of the window.
        while (low < high) {

            int mid = low + (high - low) / 2;

            // Compare the element leaving the window
            // with the element entering the next window.
            if (x - arr[mid] > arr[mid + k] - x) {
                // Move the window to the right.
                low = mid + 1;
            } else {
                // Keep the current window.
                high = mid;
            }
        }

        // The answer starts from index 'low'.
        vector<int> ans;

        for (int i = low; i < low + k; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};