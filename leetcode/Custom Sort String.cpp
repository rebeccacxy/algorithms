/*
You are given two strings order and s. All the words of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

----------------------------------------------------------------------

Edge case: s or order can be empty, but can be covered in general case

Use map to store char frequency <char,freq>

Time: O(N) = O(s.length + order.length)
Space: O(N) = O(order.length)
*/

string customSortString(string order, string s) {
	map<char,int> charFreqMap;
	for (char c : s) {
		charFreqMap[c]++;
	}
	
	string ans;
	for (char orderChar : order) {
		while (charFreqMap[orderChar] > 0) {
			ans += orderChar;
			charFreqMap[orderChar]--;
		}
	}
	for (char c : s) {
		while (charFreqMap[c] > 0) {
			ans += c;
			charFreqMap[c]--;
		}
	}
	return ans;
}















