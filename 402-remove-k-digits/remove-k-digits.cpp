class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        // Build a monotonic increasing stack
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // If k is still left, remove digits from the end
        while (k > 0) {
            st.pop();
            k--;
        }

        // Build the answer from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse because stack gives digits in reverse order
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        // If the string becomes empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};