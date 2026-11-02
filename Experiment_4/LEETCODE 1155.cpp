class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> newDp(target + 1, 0);

            for (int sum = 1; sum <= target; sum++) {
                for (int face = 1; face <= k && face <= sum; face++) {
                    newDp[sum] = (newDp[sum] + dp[sum - face]) % MOD;
                }
            }

            dp = newDp;
        }

        return dp[target];
    }
};
