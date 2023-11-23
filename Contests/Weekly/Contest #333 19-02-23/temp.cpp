// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the number of
// operation to make the N zero
int find_no_of_set_bits(long long n)
{
	// Take variable to count the number
	// of operation
	int set_bit_count = 0;
	for (int i = 0; i < 63; i++) {
		if (n & (1LL << i)) {
			set_bit_count++;
		}
	}
	return set_bit_count;
}

// Driver code
int main()
{
	long long N = 39;

	// Function call
	cout << find_no_of_set_bits(N) << endl;
	return 0;
}
