/*
Verifying an Alien Dictionary

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

----------------------------------------------------------------------

Edge case: 
- Illegal input (contains numbers / duplicates)
- empty words array, then return true.
- 1 word in words array, return true.
- word in words array is empty string, assume it has top order.

Each word of the sequence must be sorted. 

Time: O(N), where N = no. of characters in words
Space: O(1) – store mapping of letters to index
*/

bool isAlienSorted(vector<string>& words, string order) {  
    unordered_map<char, int> map;
	for (int i = 0; i < size(order); i++) {
		map[order[i]] = i;  // map letter to corresponding index in order
	}
	for (int i = 0; i < size(words) - 1; i++) {
		if (!checkOrder(words[i], words[i + 1], map)) {
			return false;
		}
	}
	return true;       
}   

// check if two words are lexicographically sorted
bool checkOrder(string& a, string& b, unordered_map<char, int> map){
	int i = -1;
	while (++i < size(a) && i < size(b)) {
		if (map[a[i]] != map[b[i]]) {
			return map[a[i]] < map[b[i]];
		}
	}
	return size(a) <= size(b);
}

















