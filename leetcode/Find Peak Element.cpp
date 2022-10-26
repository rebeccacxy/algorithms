/*
Find Peak Element I 
A peak element is an element that is strictly greater than its neighbors.
Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞.

-----------------------------------------------------------------------

Edge case: only 1 element in nums, return element at 0 index

Use binary search to check if middle element is the peak element. If element on the right side > middle element, there exists a peak element on the right side. If element on the left side > middle element, there exists a peak element on the left side. Recurse and find peak in O(log n) time.

Example: nums = [3,7,5,4,2]
5 is mid. 7 > 5 --> 7 is peak element

low = 0, high = 4, mid = 2
Since 5 > 4, high = 2, mid = 1
Since 7 > 5, high = 1, mid = 0
Since 3 < 7, low = 1, and high = low, so exit while loop, return nums[1] = 7

Example: nums = [9,7,5,4,2]
5 is mid. 7 > 5. If all elements in increasing order from mid to left, first element will be peak element --> 9 is peak element

low = 0, high = 4. mid = 2
Since 5 > 4, high = 2, mid = 1
Since 7 > 5, high = 1. mid = 0
Since high = low, exit the while loop, return nums[0] = 9

Time: O(log n)
Space: O(1)
*/

// iterative
int findPeakElement(vector<int>& nums) {
	int low = 0, high = nums.size() - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (nums[mid] < nums[mid + 1]) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	return low;
} 





// recursive – Space O(log n)
int helper(vector<int>& nums, int low, int high) {
	int n = nums.size();
	int mid = low + (high - low) / 2;
	if ((mid == 0 || nums[mid - 1] <= nums[mid]) && mid == n-1 || (nums[mid + 1] <= nums[mid])) {
		return mid;
	} else if (mid > 0 && nums[mid - 1] > nums[mid]) {
		return helper(nums, low, mid - 1);
	} else {
		return helper(nums, mid + 1, high);
	}
}

int findPeakElement(vector<int>& nums) {
	int n = nums.size();
	return helper(nums, 0, n-1);
}





/*
Find a Peak Element II

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

-----------------------------------------------------------------------

Binary search based solution. Find just the max of middle column, so only calculate max of log(N) columns.

Consider mid column and find maximum element in it.
If max >= A[index][mid-1] & max >= A[index][pick+1], max is a peak, return max.
If max < mat[max_index][mid-1], recurse on left half of matrix.
If max < mat[max_index][mid+1], recurse on right half of matrix.

Time: O(m log n) where m = rows, n = columns
Space: O(n)
*/

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int startCol = 0, endCol = mat[0].size()-1;
    
    while (startCol <= endCol) {
        int maxRow = 0, midCol = startCol + (endCol - startCol)/2;
        
        for (int row = 0; row < mat.size(); row++) {
            maxRow = mat[row][midCol] >= mat[maxRow][midCol] ? row : maxRow;   
        }
        
        bool leftIsBig = midCol-1 >= startCol && mat[maxRow][midCol-1] > mat[maxRow][midCol];
        bool rightIsBig = midCol+1 <= endCol && mat[maxRow][midCol+1] > mat[maxRow][midCol];
        
        if (!leftIsBig && !rightIsBig) { // found peak element
            return vector<int>{maxRow, midCol};
    	}
        
        else if (rightIsBig) { 
            startCol = midCol + 1;
    	}
        
        else { // leftIsBig
            endCol = midCol - 1;
        }
    }
    return vector<int>{-1,-1};
}



/*
Assume [0,0] is the peak and traverse through the next peak element from that.

Time: O(M+N)
Space:O(N)
*/

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int startCol = mat.size();
    int endCol = mat[0].size();
    
    int i = 0, j = 0;
    
    while (true) {
        int maxI = i;
        int maxJ = j;
        
        if (i > 0 && mat[i-1][j] > mat[maxI][maxJ]) {
            maxI = i-1;
            maxJ = j;
        }
        if (j > 0 && mat[i][j-1] > mat[maxI][maxJ]) {
            maxI = i;
            maxJ = j-1;
        }
        if (i < startCol-1 && mat[i+1][j] > mat[maxI][maxJ]) {
            maxI = i+1;
            maxJ = j;
        }
        if (j < endCol-1 && mat[i][j+1] > mat[maxI][maxJ]) {
            maxI = i;
            maxJ = j+1;
        }
        
        if (i == maxI && j == maxJ) {
        	break;
        }

        i = maxI;
        j = maxJ;
    }
    
    return {i, j};
}













