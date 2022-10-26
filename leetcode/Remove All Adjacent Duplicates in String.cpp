/* 
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

-----------------------------------------------------------------------
Edge case: String is empty

Push characters into stack. If character is same as top character in stack, pop the stack until hit a different character.

Example: "abbaca"
stack = [] -> [a] -> [a,b] -> [a] (pop b) -> [] (pop a) -> [c] -> [c,a]

Time: O(N)
Space: O(N)
*/

string removeDuplicates(string s) {
	stack<char> stack;  
	string ans = "";

	for (char curr : s) {
		if (stack.empty()) {
			stack.push(curr);
		} else if (stack.top() == curr) {
			stack.pop();
		} else {
			stack.push(curr);
		}
	}

	while (!stack.empty()) {
		ans += stack.top();
		stack.pop();
	}

	reverse(ans.begin(), ans.end());
	return ans;
}




/*
Remove All Adjacent Duplicates in String II

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
-----------------------------------------------------------------------
Edge case: Empty string / k = 0

Can use stack or 2 pointer approach. Use stack here.

Push characters onto stack. stack<char, frequency>. Once frequency = k, delete top k elements from stack. Otherwise, if encounter a char that is the same as top element of stack, increment frequency. When a character does not match the previous one, push 1 to the stack.

Time: O(N)
Space: O(N)
*/

string removeDuplicates(string s, int k) {
    stack<int> frequencies;
    for (int i = 0; i < s.size(); i++) {
    	if (frequencies.empty() || s[i] != s[i-1]) {
    		frequencies.push(1);
    	} else if (++frequencies.top() == k) {
    		frequencies.pop();
    		s.erase(i - k + 1, k); // erase last k characters
    		i = i - k;
    	}
    } 
    return s;
}





/*
Facebook variant: Any sequence of 3 OR MORE like items should be removed

Time: O(N)
Space: O(N)
*/

string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;
    
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || s[i] != st.top().first) {
            if (!st.empty() && st.top().second >= k) {
                st.pop(); 
                i--;
            } else {
                st.push({s[i], 1});
            }
        } else {
            st.top().second++;
        }
    }
    
    if (!st.empty() && st.top().second >= k) {
    	st.pop();
    }
    
    string res = "";
    
    while (!st.empty()) {
        auto [c, freq] = st.top(); 
        st.pop();
        res = string(freq, c) + res;
    }
    
    return res;
}








