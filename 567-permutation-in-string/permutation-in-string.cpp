class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        // Count characters of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int k = s1.length();

        // Sliding window
        for (int i = 0; i < s2.length(); i++) {

            // Add current character
            freq2[s2[i] - 'a']++;

            // Remove character outside the window
            if (i >= k) {
                freq2[s2[i - k] - 'a']--;
            }

            // Check when window size becomes k
            if (i >= k - 1) {
                bool same = true;

                for (int j = 0; j < 26; j++) {
                    if (freq1[j] != freq2[j]) {
                        same = false;
                        break;
                    }
                }

                if (same)
                    return true;
            }
        }

        return false;
    }
};
