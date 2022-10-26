/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:
    - It is the empty string, contains only lowercase characters, or
    - It can be written as AB (A concatenated with B), where A and B are valid strings, or
    - It can be written as (A), where A is a valid string.

-----------------------------------------------------------------------

Edge case: s empty string or illegal input? If no then no edge cases.

Optimise – Don't use stack (extra space). Instead keep a count variable for storing number of opening / closing brackets. 

Example: s = "))(("
count = 1->2->1->0
s = "####" --> ""

Time: O(n) = O(n+n+n) – Each step takes O(n) time
Space: O(1)
*/

// input = a)b(c)d, output = ab(c)d
string minRemoves(string s) {
    int n = s.length();
    /*
    Step 1.
    Initialise count = 0. Use count for storing no. of open brackets
    Iterate string s from start and at each iteration:
    - If open bracket found, increase count
    - If close bracket, check if no. of close brackets > open brackets, then mark that character in s by replacing it with '#', else decrease the count (matching parentheses found) 
    */
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        /* 
            s[i] = a#b(c)d 
        */
        if (s[i] == '(') {
            count++;                    // count = 2
        } else if (s[i] == ')') {
            if (count == 0) { // if no. of close brackets > open brackets
                s[i] = '#';
            } else {
                count--; // if matching parentheses found
                                       // count = 0
            }
        }
    }

    /*
    Step 2. Iterate from end 
    Again, make count = 0. Use count for storing number of close brackets
    Iterate string s from end and at each iteration:
    - If close bracket, increase count
    - If open bracket, check if no. of open brackets > close brackets, then mark that charcater in s by replacing it with '#', else decrease the count (matching parentheses found)
    */

    count = 0;
    for (int i = n-1; i >= 0; i--) {
        /* 
            s[i] = d)c(b#a
        */
        if (s[i] == ')') {
            count++;                // count = 1
        }
        else if (s[i] == '(') {
            if (count == 0) { // if no. of open brackets > close brackets
                s[i] = '#';
            } else {
                count--; // if matching parentheses found 
                                   // count = 1 - 1 = 0
            }
        }
    }

    /*
    Step 3.
    Iterate string s and append each non-marked character ('#') to ans string.
    */
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != '#'){ 
            ans.push_back(s[i]);
        }
    }
    return ans; // ab(c)d

}






/*
Minimum Add to make Parentheses Valid

A parentheses string is valid if and only if:
    It is the empty string,
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
    For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Keep track of number of '(' and number of ')'. For every open bracket we increase the count. There are 2 cases: Either it is part of a matching pair, or incomplete.  
String is valid if the difference in number is 0, and every prefix has a count greater than 0.

Time: O(N)
Space: O(1)
*/

int minAddToMakeValid(string s) {
    int open = 0, close = 0;
    for (char curr : s) {
        if (curr == '(') {
            open++;
        } else if (curr == ')') {
            if (open > 0) {
                open--; // matching pair found
            } else {
                close++;
            }
        }
    }
    return open + close;
}













