
#include "bdc.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
Dynamic Programming Approach to Find the Largest Divisible Subset:

Time Complexity:
- Previous Recursive Approach: O(2^n), since it explored all subsets recursively.
- Current DP Approach: O(n^2), where n is the size of the input.
  We compare each element with all elements before it to build up the solution.

Space Complexity:
- O(n) for both dp[] and prev[] arrays used to reconstruct the result.

Explanation:
- dp[i] stores the size of the largest divisible subset ending at input[i].
- prev[i] stores the index of the previous element in the optimal subset.
- After populating dp[] and prev[], we backtrack from the index with the largest dp[] value to reconstruct the result.
*/

vector<int> biggest_divisible_conglomerate(vector<int> input) {
    if (input.empty()) return {};
    if (input.size() == 1) return input;

    sort(input.begin(), input.end()); // Sorting helps with divisibility logic

    int n = input.size();
    vector<int> dp(n, 1);       // dp[i] = size of largest divisible subset ending at i
    vector<int> prev(n, -1);    // prev[i] = previous index in the subset ending at i
    int maxIndex = 0;           // Index of the largest value in dp[]

    // Build dp[] and prev[] arrays
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (input[i] % input[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    // Reconstruct the largest divisible subset
    vector<int> result;
    for (int i = maxIndex; i != -1; i = prev[i]) {
        result.push_back(input[i]);
    }

    reverse(result.begin(), result.end());
    return result;
}

// Utility function to convert a vector to a string representation for output
string vec_to_string(vector<int> v) {
    string result = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        result += to_string(v[i]);
        if (i < v.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}








































