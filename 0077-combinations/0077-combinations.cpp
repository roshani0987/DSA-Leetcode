class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int start, int n, int k) {
        // If we have k numbers, store the combination
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Choose numbers from start to n
        for (int i = start; i <= n; i++) {
            current.push_back(i);

            backtrack(i + 1, n, k);

            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};