/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

    For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    For example, the next permutation of arr = [1,2,3] is [1,3,2].
    Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

Given an array of integers nums, find the next permutation of nums.

-----------------------------------------------------------------------
Edge case: Size of array < 2 then return

2 situations: 
1. cannot find the number --> reverse array
2. can find number --> start from rightmost to leftward, try to find the first number which is larger than the pivot

Algorithm:
1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done
2. Find the largest index l > k such that nums[k] < nums[l]
3. Swap nums[k] and nums[l]
4. Reverse the sub-array nums[k+1:end] --> nums[k+1:end] must be non-increasing

Example:
input: [2,3,6,5,4,1]
Find first number that does not increase in ascending order --> 3
From right to left, find first number larger than 3 --> 4
Swap 3 and 4 --> [2,4,6,5,3,1]
Reverse numbers on right of 4 --> [2,4,1,3,5,6]

Time: O(N)
Space: O(1) – in-place
*/

void nextPermutation(vector<int>& nums) {
	if (nums.size() < 2) {
		return;
	}

	int transitionIndex = -1;
	for (int i = nums.size() - 1; i > 0; i--) {
		if (nums[i - 1] < nums[i]) {
			transitionIndex = i - 1;
			break;
		}
	}
	if (transitionIndex < 0) {
		reverse(nums.begin(), nums.end());
	} else {
		int nextGreaterIndex = transitionIndex + 1;
		for (int i = nums.size() - 1; i > transitionIndex; i--) {
			if (nums[i] > nums[transitionIndex]) {
				nextGreaterIndex = i;
				break;
			}
		}
		swap(nums[transitionIndex], nums[nextGreaterIndex]);
		reverse(nums.begin() + transitionIndex + 1, nums.end());
	}
}

















