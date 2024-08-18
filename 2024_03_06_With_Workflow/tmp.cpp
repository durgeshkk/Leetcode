#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, k;
vector<vector<vector<int>>> dp;  // 3D DP table for memoization

// Recursive function to build the palindrome
string solve(int index, bool tight, int remainder, string &half) {
    if (index == half.size()) {
        // We have completed the half part, now check if the palindrome is divisible by k
        return remainder == 0 ? half : "-1";
    }
    
    // If the result is already computed, return it
    if (dp[index][tight][remainder] != -1) {
        return dp[index][tight][remainder] ? half : "-1";
    }
    
    // Determine the limit for the current digit
    int limit = tight ? half[index] - '0' : 9;
    
    // Try placing digits from the limit down to 0
    for (int digit = limit; digit >= 0; --digit) {
        // Build the new half string with this digit
        half[index] = digit + '0';
        
        // Recurse for the next index
        string result = solve(index + 1, tight && (digit == limit), (remainder * 10 + digit) % k, half);
        
        if (result != "-1") {
            dp[index][tight][remainder] = 1;
            return result;
        }
    }
    
    dp[index][tight][remainder] = 0;
    return "-1";
}

// Function to generate the largest k-palindromic number
string largestPalindrome(int n_, int k_) {
    n = n_;
    k = k_;
    int halfLen = (n + 1) / 2;  // Half the length of the palindrome
    
    // Initialize DP table with -1 (uncomputed)
    dp = vector<vector<vector<int>>>(halfLen, vector<vector<int>>(2, vector<int>(k, -1)));
    
    // Create a half string filled with '9'
    string half(halfLen, '9');
    
    // Solve for the largest half palindrome that works
    string result = solve(0, true, 0, half);
    
    if (result == "-1") return "-1";  // No valid palindrome found
    
    // Build the full palindrome from the half
    string fullPalindrome = result;
    if (n % 2 == 0) {
        fullPalindrome += string(result.rbegin(), result.rend());
    } else {
        fullPalindrome += string(result.rbegin() + 1, result.rend());
    }
    
    return fullPalindrome;
}

int main() {
    int n = 5, k = 7;
    cout << largestKPalindromic(n, k) << endl;  // Expected output: a large 5-digit palindrome divisible by 7
    return 0;
}
