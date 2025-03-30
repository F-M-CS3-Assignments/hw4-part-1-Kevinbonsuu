
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








































/* #include "bdc.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Helper function to find the longest valid subset recursively
// It tries adding each number to the current subset and checks if divisibility holds
void findLargestConglomerate(vector<int>& input, vector<int>& current, vector<int>& best, int index) {
    // Base case: if we reach the end of the list
    if (index == static_cast<int>(input.size())) {  // FIX: Properly cast size comparison
        // Update best if the current conglomerate is the largest found so far
        if (current.size() > best.size()) {
            best = current;
        }
        return;
    }

    // Check if the current number can be added to the conglomerate
    bool canAdd = true;
    for (int num : current) {
        if (max(num, input[index]) % min(num, input[index]) != 0) {
            canAdd = false;
            break;
        }
    }

    // If the number can be added, include it in the subset and recurse further
    if (canAdd) {
        current.push_back(input[index]);
        findLargestConglomerate(input, current, best, index + 1);
        current.pop_back(); // Backtrack to explore other possibilities
    }
    
    // Explore the scenario where the number is not included
    findLargestConglomerate(input, current, best, index + 1);
}

// Main function to find the biggest divisible conglomerate
vector<int> biggest_divisible_conglomerate(vector<int> input) {
    if (input.empty()) return {}; // Edge case: empty input
    if (input.size() == 1) return input; // Edge case: single number input
    
    sort(input.begin(), input.end()); // Sorting helps simplify divisibility checks
    vector<int> best, current;
    findLargestConglomerate(input, current, best, 0);
    return best;
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
*/