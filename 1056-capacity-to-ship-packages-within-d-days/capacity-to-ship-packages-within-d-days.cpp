class Solution {
public:

    int countDays(vector<int>& weights, int capacity) {

        int days = 1;
        int sum = 0;

        for (int weight : weights) {

            if (sum + weight <= capacity) {
                sum += weight;
            }
            else {
                days++;
                sum = weight;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for (int weight : weights) {
            high += weight;
        }

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int requiredDays = countDays(weights, mid);

            if (requiredDays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};