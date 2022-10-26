/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

-----------------------------------------------------------------------

Approach 1: Min heap
Time: O(N log k)
Space: O(k)


Approach 2: Quickselect
kth largest element is the same as N-kth smallest element, so can implement kth smallest algorithm for this problem.
- Choose a pivot
- Use a partition algorithm to place the pivot into position in the sorted array, move smaller elements to left of pivot, equal or larger ones to the right of pivot
- Compare position and N-k to choose side of array to recurse on.

Eg. k = 2, [4, 3, 5, 9, 8, 7]. Suppose we pick the pivot as the last number 7. We can separate the array into [4, 3, 5] 7 [9, 8] which means we get 3 smaller numbers. Then recursively do the same step to right array until we get a proper N-k.

Time: O(N) avg, O(N^2) worst
Space: O(1) in place
*/


// Quickselect

// input: nums = [3,2,1,5,6,4], k = 2
int findKthLargest(vector<int>& nums, int k) {
	int left = 0, right = nums.size() - 1, index = 0;
	while (true) {
		index = partition(nums, left, right);
		if (index == k - 1) {
			break;
		}
		else if (index < k - 1) {
			left = index + 1;
		}
		else { // pivot less than k-1
			right = index - 1;
		}
	}
	return nums[index];
}

int partition(vector<int>& nums, int left, int right){ // hoare partition
	int pivot = nums[left], l = left + 1, r = right;
	// pivot = 3
	while (l <= r){
		if (nums[l] < pivot && nums[r] > pivot) {
			swap(nums[l++], nums[r--]);
		}
		if (nums[l] >= pivot) {
			l++;
		}
		if (nums[r] <= pivot) {
			r--;
		}
	}
	swap(nums[left], nums[r]);
	return r;
}



// Min heap


















