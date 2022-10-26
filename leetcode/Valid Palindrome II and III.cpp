/*
Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most ONE character from it.

----------------------------------------------------------------------

Edge case: Since string is non-empty, no edge cases. 

2 pointer approach. Use 2 pointers to traverse the string, one pointer starts from the string's left, the other starts from right.
During the traversal, left and right pointers move by one position each time. If left and right chars are not equal, check if the rest of string without the left char or right char is a palindrome.

Example:
ababca --> since b != c, isPalindrome returns false, delete c
s -->            
 <-- e

Example:
a --> since i = j, return true

Time: O(N)
Space: O(1)
*/

bool isPalindrome(string s, int i, int j) {
    // i is at 0th index; j is at last index
    while (i < j) {
        if (s.at(i) == s.at(j)) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    int i  = 0;
    int j = s.size() - 1;
    while (i < j) {
        if (s.at(i) == s.at(j)) {
            i++;
            j--;
        } else {
            return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
        }
    }
    return true;
}


/*
Valid Palindrome III

Given a string s and an integer k, return true if s is a k-palindrome.
A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.

https://leetcode.com/problems/valid-palindrome-iii/solution/

----------------------------------------------------------------------

Use recursion and optimise with dp.
dp[i][j]
Check dp[i+1][j-1]. if a....a is palindrome, then substring from i+1 and j-1 is also palindrome.

if s[i] == s[j] check if same 
else min(dp[i+1][j], dp[i][j-1]) + 1 // need to remove 1 char, plus 1 as current i and j are different
Return dp[1][n] <= k

Time: O(N^2)
Space: O(N^2)
*/

int isPalindrome(int start, int end, string &s,vector<vector<int> > &dp){
        if (start > end) {
        	return 0;
        }
        if (dp[start][end] != -1) {
        	return dp[start][end];
        }
        if (s[start] == s[end]) {
        	return dp[start][end] = isPalindrome(start+1, end-1, s, dp);
        } else {
        	return dp[start][end] = 1 + min(isPalindrome(start+1, end, s, dp), isPalindrome(start, end-1, s, dp));
        }
    }
    
bool isValidPalindrome(string s, int k) {
    int start= 0;
    int end = s.length()-1;
    vector<vector<int> > dp(end+1,vector<int>(end+1, -1));
    return isPalindrome(start,end,s,dp) <= k;
}










