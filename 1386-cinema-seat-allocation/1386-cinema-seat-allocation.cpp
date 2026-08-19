class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Store reserved seats for only the rows that have reservations.
        unordered_map<int, int> reserved;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            reserved[row] |= (1 << col);
        }

        int ans = (n - reserved.size()) * 2;

        for (auto &[row, mask] : reserved) {
            // Seats 2,3,4,5
            bool left = (mask & (1 << 2)) == 0 &&
                        (mask & (1 << 3)) == 0 &&
                        (mask & (1 << 4)) == 0 &&
                        (mask & (1 << 5)) == 0;

            // Seats 6,7,8,9
            bool right = (mask & (1 << 6)) == 0 &&
                         (mask & (1 << 7)) == 0 &&
                         (mask & (1 << 8)) == 0 &&
                         (mask & (1 << 9)) == 0;

            // Seats 4,5,6,7
            bool middle = (mask & (1 << 4)) == 0 &&
                          (mask & (1 << 5)) == 0 &&
                          (mask & (1 << 6)) == 0 &&
                          (mask & (1 << 7)) == 0;

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};