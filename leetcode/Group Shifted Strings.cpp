/*
We can shift a string by shifting each of its letters to its successive letter.
    For example, "abc" can be shifted to be "bcd".
We can keep shifting the string to form a sequence.
    For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

-----------------------------------------------------------------------
Edge case: Empty words, duplicate words in strings, if output should be in any order

Brute force: 2 nested for loops to compare all pairs to see if 1 string is shift of the other. avg length of word = N, M words. Time: O(M^2*N)

better: Store all words in a hashmap, then iterate input array, try to generate all 26 possible shifts for each string. Time: O(N^2) = O(M*N)

optimised: Compute shifting between each letter in word, then put shifting into a hashmap. Map<String (shifting pattern), List<String> (strings with shifting pattern)> . Suppose w1 has same shifting pattern as w2, then can shift w1 to w2. 

"az" and "ba" belong to the same shifting pattern -> if s[i] - s[i - 1] is negative, need to add 26 to it to make it positive and give the correct result

Example: 
"abc" -> "1,1"
"acf" -> "2,3" (f is 3 larger than c)

Example: ["abc","bcd","acef","xyz","az","ba","a","z"]
findPattern("abc") -> "1,1"
patternWordsMap = {
	"1,1," : ["abc", "bcd", "xyz"]
	"2,2,1,": ["acef"]
	"25": ["az", "ba"]
	",": ["a", "z"]
}

Time: O(N^2) = O(M*N)
Space: O(N^2) = O(M*N)
*/

string findPattern(string word) {
	if (word.size() == 0) {
		return "";
	}
	if (word.size() == 1) {
		return ",";
	}

	string pattern;
	for (int i = 1; i < word.length(); i++) {
		int diff = word[i] - word[i-1];
		if (diff < 0) {
			diff += 26;
		}
		pattern += 'a' + diff + ',';
	}
	return pattern;
}

vector<vector<string>> groupStrings(vector<string>& strings) {
	vector<vector<string>> groups;
	unordered_map<string, vector<string>> patternWordsMap;
	
    for (string s : strings) {
        patternWordsMap[findPattern(s)].push_back(s);
    }
    for (auto m : patternWordsMap) {
        vector<string> group = m.second;
        sort(group.begin(), group.end()); // only if output in lexicographical order
        groups.push_back(group);
    }
    return groups;
}








