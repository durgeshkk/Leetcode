#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate the number of good strings
int countGoodStrings(int n) {
    // Initialize a 2D array to store the counts
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    // Base case: empty string
    for (int j = 0; j < 4; ++j) {
        dp[0][j] = 1;
    }

    // Dynamic programming to fill the array
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            // Update the count based on the possible transitions
            for (int k = 0; k < 4; ++k) {
                if (j != k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    // Sum the counts for all possible endings with "leet"
    int result = 0;
    for (int j = 0; j < 4; ++j) {
        result = (result + dp[n - 1][j]) % MOD;
    }

    return result;
}

int main() {
    int n = 4; // You can change the value of n
    int result = countGoodStrings(n);
    cout << result << endl;

    return 0;
}
