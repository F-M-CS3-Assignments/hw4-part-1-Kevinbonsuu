
#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>


int main() {

	// Test 1 (example from assignment description)
	vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
	vector<int> ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> answerSet(ans.begin(), ans.end());
	set<int> soln = {56, 14, 7, 28};
	bool first = (answerSet == soln);
	soln = {56, 28, 14, 2};
	bool second = (answerSet == soln);
	assert(first || second);


	// Test 2
	values = {10, 5, 3, 15, 20};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	soln = {20, 5, 10};
	set<int> answerSet2(ans.begin(), ans.end());
	assert(answerSet2 == soln);

	// write your own tests here!

		// Test 3: List with only one number
	values = {42};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans == values);  // Should return the same number

	// Test 4: List with no valid divisible pairs
	values = {7, 11, 17, 3};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans.size() == 1);  // Should return one element

	// Test 5: List with multiple valid solutions
	values = {3, 6, 12, 24, 48};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> soln1 = {3, 6, 12, 24, 48};
	set<int> soln2 = {6, 12, 24, 48};  // Another valid solution
	set<int> answerSet3(ans.begin(), ans.end());
	assert(answerSet3 == soln1 || answerSet3 == soln2);

	// Test 6: Empty list
	values = {};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	assert(ans.empty());  // Should return an empty list

	// Test 7: Large numbers
	values = {100, 200, 400, 800, 1600};
	ans = biggest_divisible_conglomerate(values);
	cout << "input: " << vec_to_string(values) << endl;
	cout << "output: " << vec_to_string(ans) << endl << endl;
	set<int> soln3 = {100, 200, 400, 800, 1600};
	set<int> answerSet4(ans.begin(), ans.end());
	assert(answerSet4 == soln3);


	return 0;
}
