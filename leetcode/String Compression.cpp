/*
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

    If the group's length is 1, append the character to s.
    Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

-----------------------------------------------------------------------
Edge case: If length of array <= 1, just return it.

2 pointer approach: Increment second pointer and count variable until find a different char, then update first pointer and the char array. 
Write to element at i and read from element at j.

Time: O(N)
Space: O(1)
*/

int compress(vector<char>& chars) {
	int n = chars.size();
	if (n <= 1) {
		return n;
	}
	int i = 0, j = 0;
	while (j < n) {
		int count = 0;
		char curr_char = chars[j];
		while (j < n && chars[j] == curr_char) {
			count++;
			j++;
		} 
		chars[i++] = curr_char;
		if (count > 1) { // add count of each char
			string counter = to_string(count);
			for (char c : counter) {
				chars[i++] = c;
			}
		}
	}
	return i;
}















