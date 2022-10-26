/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

https://leetcode.com/problems/subarray-sum-equals-k/solution/

----------------------------------------------------------------------

Edge case: No prefix sum exists yet, so need to initialise <0,1> 

Map the frequency of prefix sum and calculate remaining sum (prefix sum minus k). Check if the remaining sum is present in the map. If present, it means that a subarray exists which has a sum equal to k, so increment count, otherwise 0 gets added. Increase the frequency of prefix sum in the map and return the count. 

Example: input = [1,2,1,3], k = 3
prefix sum = [1,3,4,7] --> 2 subarrays of sum = k found (1->4, 4->7)
But original array has 3 subarrays, so need to add a 0 --> 3-0 = k
prefix sum = [0,1,3,4,7]

Time: O(N)
Space: O(N)
*/

int subarraySum(vector<int>& nums, int k) {
	unordered_map<int,int> map;
	map[0] = 1; // put 0 frequency as 1
	int sum = 0, count = 0;

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i]; // calculate prefix sum
		int remainingSum = sum - k; // calculate remaining sum
		count += map[remainingSum]; // if remaining sum is alr present, add the frequency. otherwise 0 gets added
		map[sum]++; // increase frequency of sum in map
	}
	return count;
}




/*
Given a sequence of positive integers nums and an integer k, return whether there is a continuous sequence of nums that sums up to exactly k.

----------------------------------------------------------------------

Use a set to store prefix sum. 

Time: O(N)
Space: O(N)
*/

public boolean consecutiveSum(vector<int> nums, int k) {

	if (nums == null || nums.length() == 0) {
		return false;
	}

	set<int> set;

	int sum = 0;
	int diff = 0;

	for (int i = 0; i < nums.length(); i++) {
		sum += nums[i];   
		if (sum == k) {
			return true;
		}

		diff = sum - k ;   

		if (set.contains(diff)){
		    return true;   
		} else {
		   set.insert(sum);   
		}

	}

	return false;

}












