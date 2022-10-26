/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

-----------------------------------------------------------------------
Edge case: Empty array

2 binary searches, one for finding start position and end position. Check if target exists in array by checking nums[start]. If don't find target at that index, then target does not exist in array.
Then find right end of target values. Use same binary search, 

Example: [5,7,7,8,8,8], target = 8
start index:
start = 0, end = 5, mid = 2
start = 3, end = 5, mid = 4 but want leftmost 8
move end = mid - 1 = 3 --> startIndex = 3

end index:
start = 0, end = 5, mid = 2
start = 3, end = 5, mid = 4 but want rightmost 8
move start = mid + 1 = 5
start = 5, end = 5, mid = 5 --> endIndex = 5

Time: O(log N)
Space: O(1)
*/

int startIndex(vector<int>& nums, int target) {
	// first occurrence
	int start = 0, end = nums.size() - 1;
	int potentialTarget = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] < target) {
			start = mid + 1; // search on right part
		} else if (nums[mid] > target) {
			end = mid - 1; // search on left part
		} else {
			potentialTarget = mid;
			end = mid - 1;
		}
	}
	return potentialTarget;
}

int endIndex(vector<int>& nums, int target) {
	// last occurrence
	int start = 0, end = nums.size() - 1;
	int potentialTarget = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] < target) {
			start = mid + 1; // search on right part
		} else if (nums[mid] > target) {
			end = mid - 1; // search on left part
		} else {
			potentialTarget = mid;
			start = mid + 1;
		}
	}
	return potentialTarget;
}

vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.size() == 0) {
		return {-1, -1};
	}
	int left = startIndex(nums, target);
	int right = endIndex(nums, target);

	return {left, right};  
}













