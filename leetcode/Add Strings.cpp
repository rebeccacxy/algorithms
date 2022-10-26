/*
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

Note:
1. when result < 10, change add to 0
2. At the end of the calculation, if add == 1, add one more digit at the beginning of the string
3. In while loop, remember to i--, j--. Otherwise, dead loop

Time: O(max(N1, N2)), where N1, N2 = length of num1, num2
Space: O(max(N1, N2)), as length of new string is at most max(N1, N2) + 1
*/

string addStrings(string num1, string num2) {
    int i = num1.length()-1;  // last index of num1 
    int j = num2.length()-1; // last index of num2
    int carry = 0; // initial carry is 0
    string res; 
    while(i >= 0|| j >= 0) {
        int sum = carry; // assign carry to sum
        if (i >= 0) sum += num1[i--]-'0'; // if the iterator index has not reached 0,add number to sum
        if (j >= 0) sum += num2[j--]-'0';
        res += to_string(sum%10); // appending the last character to res
        carry = sum / 10; // the rest of the characters to carry
    }
    if (carry > 0) {
        res += to_string(carry); // if there is a carry forward, append it to res
    }
    reverse(res.begin(),res.end()); // reverse the resultant as we calculated it from reverse.
    return res;
}

