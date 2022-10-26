/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

-----------------------------------------------------------------------
is input intervals sorted?
- if not sorted, sort array using start number

Edge case: input array size <= 1

Example: intervals = [[1,3],[2,6],[8,10],[15,18]]

Add [1,3] in a temporary array. Then visit [2,6]. Since 2 < 3, has overlap -> can merge to be [1,6]. Since 8 > 6, no overlap, add to temp array. 15 > 10, no overlap, add again. 

Time: O(Nlog N)
Space: O(log N) or O(N). If sort intervals in place, then O(1)

Follow up: https://leetcode.com/problems/merge-intervals/discuss/1444462/Followup-BST-Implementation-C%2B%2B
*/

// input: intervals = [[1,3],[2,6],[8,10],[15,18]]
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
    	return intervals;
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    merged.push_back(intervals[0]); // merged = [1,3]
    for (vector<int> interval : intervals) {
    	if (merged.back()[1] >= interval[0]) {
    		// update endpoint of final element of merged if there is an overlap with interval
    		merged.back()[1] = max(merged.back()[1], interval[1]); // merged = [1,6], [8, 10], [15, 18]
    	} else {
    		// if no overlap, insert interval
    		merged.push_back(interval);
    	}
    }
    return merged;
}




/*
Merge 2 Non-Overlapping interval lists

Given A and B two interval lists, A has no overlap inside A and B has no overlap inside B. Merge two interval lists, output the result with no overlap.

A: [1,5], [10,14], [16,18]
B: [2,6], [8,10], [11,20]
output: [1,6], [8, 20]

https://leetcode.com/discuss/interview-question/124616/Merge-two-interval-lists
-----------------------------------------------------------------------
Edge case: Either list is null

2 pointer approach

Time: O()
Space:
*/

// vector<pair<int, int>> mergeNonOverlappingIntervals(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
// 	if (a.size() == 0) {
// 		return b;
// 	} else if (b.size() == 0) {
// 		return a;
// 	}

//     int s = INT_MIN, e = INT_MIN, i = 0, j = 0;
//     vector<pair<int,int>> res;
//     while (i < a.size() || j < b.size()) { // Move pointers to merge
//         pair<int, int> cur;
//         if (i >= a.size()) cur = b[j++];
//         else if (j >= b.size()) cur = a[i++];
//         else cur = a[i].first < b[j].first ? a[i++] : b[j++];
//         if (cur.first > e) {
//             if (e > INT_MIN)
//                 res.emplace_back(s, e);
//             s = cur.first;
//             e = cur.second;
//         }
//         else {
//             e = max(cur.second, e);
//         }
//     }
//     if (e > INT_MIN) res.emplace_back(s, e);
//     return res;
// }



/*
Imagine you have a file download manager with given file length that receives a stream of bits defined as intervals.
Every time it receives bits with add(), it returns true / false whether the file transfer has completed:.
Suggest an implementation."

dm = DownloadManager(11)
dm.add([10, 11]) -> false
dm.add([7, 8]) -> false
dm.add([2, 5]) -> false
dm.add([0, 3]) -> false
dm.add([6, 9]) -> true

-----------------------------------------------------------------------
Edge case: 

Time: O(Nlog N)
Space: O(N)
*/

// JAVA
class Solution {
	private PriorityQueue<int[]> pq;
	int n;
	public Solution(int n) {
	    pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
	    this.n = n;
	}

	public boolean DownloadManager(int[] interval) {
	    if (interval == null || interval.length != 2)
	        return false;
	    
	    pq.add(interval);
	    
	    if (pq.size() > 1) {
	        mergeIntervals(pq);
	    }
	    
	    if (pq.size() == 1) {
	       if (pq.peek()[0] == 0 && pq.peek()[1] == n) {
	           return true;
	       }
	    }
	    return false;
	}

	private void mergeIntervals(PriorityQueue<int[]> pq) {   
	    LinkedList<int[]> merged = new LinkedList<>();

	    while(!pq.isEmpty()) {
	        int[] interval = pq.poll();
	        
	        if (merged.isEmpty() || merged.getLast()[1] < interval[0] - 1) {
	            merged.addLast(interval);
	        } else {
	            merged.getLast()[1] = Math.max(merged.getLast()[1], interval[1]);
	        }
	    }
	    pq.addAll(merged);
	}
}








