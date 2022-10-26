/*
A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

    "s10n" ("s ubstitutio n")
    "sub4u4" ("sub stit u tion")
    "12" ("substitution")
    "su3i1u2on" ("su bst i t u ti on")
    "substitution" (no substrings replaced)

Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

-----------------------------------------------------------------------

2 pointer method, one for word, one for abbreviation.
Compare ith character of abbreviation with jth character of word.

2 scenarios:
- i points to a letter. Compare the value that i and j points to. If equal, we increment them. Otherwise, return False.
- i points to a digit. Need to find out complete number that i is pointing to, for eg. 123. Then increment j by 123. Then next, will either
	- Return False if i or j is too large
	- or return to first scenario

Time: O(N), where N = max(len(word), len(abbr))
Space: O(1)
*/


// input = "apple", "a3e"

bool validWordAbbreviation(string word, string abbr) {
    int j = 0; // j = pointer for word
    int num = 0;

    for (int i = 0; i < abbr.size(); i++) { // pointer for abbreviation
        if (isdigit(abbr[i])) {
        	if (abbr[i] == '0' && num == 0) { 
                return false; // edge case for leading zeros
        	} else {
            	// num = 0
                num = 10 * num + abbr[i] - '0'; // ascii: -'0' = -48
                // num = 3
            }
        } else {
        	j += num; // j = 4 
            num = 0;

            if (j < word.size() && abbr[i] == word[j]) {
                j++;
            } else {
                return false;
            }
        }
    }
    return j + num == word.size(); // 5 + 0 = 5
}








// bool validWordAbbreviation(string word, string abbr) {
//     int i = 0, j = 0;
//     while (i < word.size() && j < abbr.size()) {
//         if (isdigit(abbr[j])) {
//             if (abbr[j] == '0') { // handle edge case for leading zeros
//                 return false;
//             }
//             int val = 0;
//             while (j < abbr.size() && isdigit(abbr[j])) { 
//                 // val = 0
//                 val = val * 10 + abbr[j] - '0'; // ascii: -'0' = -48
//                 // val = 3
//                 j++;
//             }
//             i += val;
//         } else if (word[i++] != abbr[j++]) {
//             return false;
//         }
//         // i++;
//         // j++;
//     }
//     return i == word.size() && j == abbr.size();
// }










