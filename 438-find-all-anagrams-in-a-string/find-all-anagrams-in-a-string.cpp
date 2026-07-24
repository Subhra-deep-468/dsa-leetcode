class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (s.size() < p.size())
            return ans;

        vector<int> pFreq(26, 0);
        vector<int> windowFreq(26, 0);

        // Frequency of p
        for (char ch : p) {
            pFreq[ch - 'a']++;
        }

        int k = p.size();

        // First window
        for (int i = 0; i < k; i++) {
            windowFreq[s[i] - 'a']++;
        }

        // Check first window
        if (windowFreq == pFreq) {
            ans.push_back(0);
        }

        // Slide the window
        for (int i = k; i < s.size(); i++) {

            // Remove left character
            windowFreq[s[i - k] - 'a']--;

            // Add right character
            windowFreq[s[i] - 'a']++;

            // Compare frequencies
            if (windowFreq == pFreq) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};