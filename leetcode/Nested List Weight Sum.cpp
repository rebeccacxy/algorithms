/*
You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.
The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.
Return the sum of each integer in nestedList multiplied by its depth.

----------------------------------------------------------------------

Edge case: Suppose nested list only contains 1 list and it is empty, but can be taken care of by general solution. 

Can either use DFS or BFS. Because the input is nested, use DFS. Go through list of nested integers and keep track of current depth. 
1. If a nested integer is an integer n, calculate its sum as n x d. 
2. Else if nested integer is a list, recursively calculate the sum but increment depth.

Example: 
nestedList = [1,[4,[6]]]
1 is integer --> sum = 1
Next element is list [4, [6]] --> Call DFS
4 is integer --> sum = 4*2 = 8
Next element is list [6] --> Call DFS
6 is integer --> sum = 6*3 = 18
Return 18 + 8 + 1 = 27

Time: O(N) – go through each number once
Space: O(N) = O(D) recursive calls where D = depth
*/

int dfs(vector<NestedInteger>& nestedList, int depth) {
	int sum = 0;
	for (NestedInteger integer : nestedList) {
		if (integer.isInteger()) {
			sum += depth * integer.getInteger();
			continue;
		}
		sum += dfs(integer.getList(), depth + 1);
	}
	return sum;
}

int depthSum(vector<NestedInteger>& nestedList) {
	int sum = dfs(nestedList, 1);
	return sum;
}
















