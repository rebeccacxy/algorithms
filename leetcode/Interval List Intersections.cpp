/*
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

-----------------------------------------------------------------------
Edge case: If either list is empty, return empty list

2 pointer approach. 

Example:
A = [[0,2],[5,10],[13,23],[24,25]]
B = [[1,5],[8,12],[15,24],[25,26]]

pA = 0, pB = 0. Overlap -> output = [[1,2]]
pA = 1, pB = 0. Overlap -> output = [[1,2], [5,5]]
pA = 1, pB = 1...

Example: non-overlap
A = [13,23]
B = [8,12]

Time: O(N+M) where N = len(A), M = len(B)
Space: O(N+M)
*/

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> intersections;
    int pA = 0, pB = 0;
    while (pA < A.size() && pB < B.size()) {
    	int begin = max(A[pA][0], B[pB][0]); // if no overlap, beginning number will be max of beginning num of interval A and B
    	int end = min(A[pA][1], B[pB][1]); // ending number = smaller num of ending number of A and B
    	if (begin <= end) {
    		// there is interval overlap
    		intersections.push_back({begin, end});

    	}
    	if (A[pA][1] < B[pB][1]) {
    		// decide which pointer to move forward
    		// move pA if ending number is smaller one
    		pA++;
    	} else {
    		pB++;
    	}
    }
    return intersections;
}











