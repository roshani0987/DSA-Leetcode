class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        vector<int> count(128, 0);

        // Count required characters from t
        for (char c : t) {
            count[c]++;
        }

        int left = 0;
        int required = t.length();

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            // If this character is required
            if (count[s[right]] > 0) {
                required--;
            }

            count[s[right]]--;

            // Window contains all characters of t
            while (required == 0) {

                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                count[s[left]]++;

                if (count[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLength == INT_MAX
                   ? ""
                   : s.substr(start, minLength);
    }
};
