class Solution {
public:
    int climbStairs(int n) {
        // Base cases: 1 way for 1 stair, 2 ways for 2 stairs
        if (n <= 2) {
            return n;
        }
        
        int prev2 = 1; // Represents ways to reach step (i-2)
        int prev1 = 2; // Represents ways to reach step (i-1)
        int current = 0;
        
        // Iteratively calculate ways for remaining steps up to n
        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;   // Shift step (i-2) to (i-1)
            prev1 = current; // Shift step (i-1) to current
        }
        
        return current;
    }
};
