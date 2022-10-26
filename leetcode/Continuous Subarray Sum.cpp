/*
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

----------------------------------------------------------------------
Edge case: 
- If k=0 or k<0, illegal input? 
- Input array empty or 1 number -> return false

(sum_j - sum_i) % k = 0
=> sum_j % k - sum % k = 0
=> sum_j % k = sum_i % k --> relation derived

For some prefix_sum(0,j) , we need to check if there exist some prefix_sum(0,i) such that both are equal. If yes, return true. Else check for some other j. 

Map<Sum(subarray_0_to_index) % k, index>
Example:
[23, 2, 4, 6, 7]
{
	0: -1,
	23 % 6 = 5: 0,
	(23+2) % 6 = 1: 1,
	(23+2+4) % 6 = 5: 2
} -> return true

Time: O(N)
Space: O(N)
*/

bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2 || k < 0) {
    	return false;
    }
    
    unordered_map<int,int> sumIndexMap;
    sumIndexMap[0] = -1;
    int sum = 0, mod = 0;
    for (int i = 0; i < nums.size(); i++) {
    	sum += nums[i];
    	if (k != 0) {
    		mod = sum % k;
    	}
    	// check if mod already exists in hashmap
    	if (sumIndexMap.find(mod) != sumIndexMap.end()) {
    		// if exists, then current location minus the previous location must be >1
    		if (i - sumIndexMap[mod] > 1) {
    			return true;
    		}
    	} else {
    		// else if current mod doesn't exist in sumIndexMap, store it
    		sumIndexMap[mod] = i;
    	}
    }
    return false;
}















