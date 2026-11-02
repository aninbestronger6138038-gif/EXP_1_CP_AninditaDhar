class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const int MOD = 1e9 + 7;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (auto type : types) {
            int count = type[0];
            int marks = type[1];

            vector<int> newDp(target + 1, 0);

            for (int j = 0; j <= target; j++) {
                if (dp[j] == 0) {
                    continue;
                }

                for (int k = 0; k <= count && j + k * marks <= target; k++) {
                    newDp[j + k * marks] =
                        (newDp[j + k * marks] + dp[j]) % MOD;
                }
            }

            dp = newDp;
        }

        return dp[target];
    }
};
