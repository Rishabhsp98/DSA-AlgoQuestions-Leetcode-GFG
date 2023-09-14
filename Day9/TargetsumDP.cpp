
class Solution
{
public:
    int n;
    int MOD = 1e9 + 7;
    int solve(int arr[], int idx, int sum, vector<vector<int>> &dp)
    {

        if (idx < 0)
            return sum == 0;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int pick = 0;
        if (arr[idx] <= sum)
            pick = solve(arr, idx - 1, sum - arr[idx], dp);
        int notpick = solve(arr, idx - 1, sum, dp);

        return dp[idx][sum] = (pick + notpick) % MOD;
    }
    int perfectSum(int arr[], int N, int sum)
    {
        // Your code goes here
        n = N;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, n - 1, sum, dp);
    }
}
