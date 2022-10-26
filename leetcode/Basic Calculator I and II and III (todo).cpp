/*
Basic Calculator II

Given a string s which represents an expression, evaluate this expression and return its value. The integer division should truncate toward zero.

s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.

----------------------------------------------------------------------

Instead of using a stack to track values of evaluated expression, and pop values from stack and add to result, space optimisation: Add values to the result beforehand and keep track of last calculated number. 

Need to do four basic operation + , - , * , / .
Every time we got a number, we will check for last operation and aggregate it into the last_result and repeat the process until we aggregate that into the final result sum.

Time: O(N), where N = length of string s
Space: O(1)
*/

int calculate(string s) {
	int sum = 0;
	long long last = 0, last_result = 1;

	char last_operator = '+';
	if (s.size() < 1) {
		return sum;
	}
	int i = 0, sign = 1; // sign is for + and -
	while (i < s.size()) {
		if (s[i] == ' ') {
			i++;
			continue;
		}

		if (s[i] == '+' || s[i] == '-') {
			sum += last_result * sign;
			if (s[i++] == '+') {
				sign = 1;
			} else {
				sign = -1;
			}
			last_result = 1;
			last_operator = '+';
		} else if (s[i] == '/' || s[i] == '*') {
			last_operator = s[i];
			++i;
		}

		if (isdigit(s[i])) {
			last = 0;
			while (i < s.size() && isdigit(s[i])) {
				last = last * 10 + s[i] - '0'; // convert char to int 
				i++;
			}
			if (last_operator == '*') {
				last_result *= last;
			} else if (last_operator == '/') {
				last_result /= last;
			} else {
				last_result = last;
			}
		}
	}
	sum += last_result * sign;
	return sum; 
}


/*
input:  "1 + 2*3 - 5/4"

last_operator is set to be '+'
when we read '1', we check the operator before 1, it's '+', so first tempresult is 1, and "sum = 1";
when we read '+', last_operator is again reseted to be '+'
when we read 2, because the operator before 2 is '+', so 2 is the beginning number of the new operand, so we set last_result = (+) 2;
when we read *, last_operator is set to be *
when we read 3, last_result = (+) 2*3
when we read '-', last_operator is set to be '-'
when we read 5, we check the operator before 5 is '-' which indicates the end of current last_result, so we update final sum, sum = 1 + 2*3, and last is reset to be (-) 5;
when we read '/', last_operator is set to be '/'
when we read '4', because the operator before 4 is '/', update last_result = (-5) / 4.

*/









/*
Basic Calculator I

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

s consists of digits, '+', '-', '(', ')', and ' '

----------------------------------------------------------------------

When we come across + or -, add the current num * previous_sign up to now, then update the num to 0 and sign for the next num to 1 if it is positive or -1 if it is negative.

An open parenthesis "(" uses recursion which stops at its corresponding ")" , the value evaluated inside is given to num which will be added or subtracted to sum according to its sign.

Time: O(N)
Space: O(1)
*/

long long int helper(string &s, int &i) {
	int sign = 1, sum = 0;
	long long num = 0; // collects the number as we move through string

	while (i < s.size()) {
		if (s[i] == '-') {
			sum += num * sign;
			sign = -1;
			num = 0;
			i++;
		} else if (s[i] == '+') {
			sum += num * sign;
			sign = 1;
			num = 0;
			i++;
		} else if (s[i] == '(') {
			i++;
			num = helper(s, i);
			i++; // After exiting recursion, update index again so it doesnt get the same ")" in the next iteration and exit the main function instead.
		} else if (isdigit(s[i])) {
			num = num * 10 + s[i] - '0';
			i++;
		} else if (s[i] == ')') {
			sum += num * sign;
			num = 0;
			return sum;
		} else {
			i++;
		}
	}
	sum += sign * num;
	return sum;
}

int calculate(string s) {
	int i = 0;
	return helper(s, i);
}


/*
input: 10 + (21+5-(20-2)) + 5

we start with num = 0 and sign as 1
first we collect num as 10, which will be added to sum as 10*1 when we reach the first operator "+"

we leave the sign to 1 and set num to 0
now we come across "(" we move the iterator to next (2) and enter into a recursion, which will exit at the last ")" we then move the iterator to the last "+" again in the same line so the main function doesnt get exited in the next iteration.

Inside it the sum is locally 0 again and will be updated to 26 before entering the second recursion with sign as -1, the second recursion will be evaluated as 18, which will be set as the num and -1*18 will be added to the sum inside the first recursion which will become 8 which will be returned as num of the first function.

since the sign in first function is still +1 before the opening of the bracket, 8 is added to the sum
*/





/*
Basic Calculator III

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

----------------------------------------------------------------------

Time: O(N)
Space: O(N) = O(num of brackets)
*/

int calculate(string s) {
    if (s.size() == 0) {
        return 0;
    }
    
    stack<int> myStack;
    char sign = '+'; // sign only indicate next element attribute
    long number = 0;
    
    for (int i = 0; i< s.size(); i++) {
	    // Step 1. calculate the current number you meet. have a recursive call the func encounter a parenthese
        if (isdigit(s[i])) {
            number = number*10 + long(s[i]-'0');
        } else if (s[i] == '(') {
            int j = i + 1; 
            int braces = 1;
            while (braces > 0) {
                if (s[j] == '(')
                    braces++;
                else if (s[j] ==')')
                    braces--;
                j++;
            }
            
            int length = (j-1) -i ;
            number = calculate(s.substr(i + 1, length));
            i = j-1; // adjust cursor to the last calculated character
        }
        
		// Step 2.  push the current number inside your stack based on the **last sign** you meet
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size() - 1) {
            switch (sign) {
                case '+':
                    myStack.push(number);
                    break;
                case '-':
                    myStack.push(-number);
                    break;
                case '*': {
                    int top = myStack.top();
                    myStack.pop();
                    myStack.push(top*number);
                    break;                        
                }
                case '/': {
                    int top = myStack.top();
                    myStack.pop();
                    myStack.push(top/number);
                    break;                        
                }
            }

            sign = s[i]; // assign new operator 
            number = 0; // reset the current number 
        }
    }
    
	// Step 3.  sum up all the numbers you have meet by poping elements from the stack
    int sum = 0;
    while(!myStack.empty()) {
        sum += myStack.top();
        myStack.pop();
    }
    return sum;
}




















