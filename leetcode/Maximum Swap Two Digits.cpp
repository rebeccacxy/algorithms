/*
You are given an integer num. You can swap two digits at most once to get the maximum valued number. Return the maximum valued number.

---------------------------------------------------------------------

Store last occurrence of each digit in a hashmap. 
Find the largest digit in the last occurrence and replace it with the leftmost digit. 

Time: O(N)
Space: O(N)
*/

// input: num = 2736
int maximumSwap(int num) {
	string num_str = to_string(num);

	unordered_map<int, int> map; // map last occurrence of each digit 
								 // <digit, index>
    int digits[9];
	for (int i = 0; i < num_str.size(); i++) {
		digits[i] = num_str[i] - '0';
		map[digits[i]] = i;
	}

	// map = {6, 3} {3, 2} {7, 1} {2, 0}

	for (int i = 0; i < num_str.size(); i++) {
		for (int j = 9; j > digits[i]; j--) { // O(1) from 9 to 0
			if (map[j] > i) {
				swap(num_str[map[j]], num_str[i]); // if larger digit later, swap
				// swap(n[map[1]], n[0]) = swap(2, 7)
				return stoi(num_str);
			}
		}
	}
	return stoi(num_str);
}








