class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i = 0; // Pointer for s
        int j = 0; // Pointer for t

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        // If we've matched all characters in s,
        // then s is a subsequence of t.
        return i == s.size();
    }
};