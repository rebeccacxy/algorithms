/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

-----------------------------------------------------------------------
Edge case: If empty array, return 0. If < 3 bars, return 0.

2 pointer approach. Find longest bar on left and right, and maintain leftMax and rightMax during iteration.

Example: [6,0,5,0,4]
Longest bar on left = 6, right = 5 -> hold 5 water
At index 3, longest bar on left = 6, right = 4 -> cannot hold water 
At index 4, longest bar on left = 6, right = 4 -> can hold 4 water
total = 5 + 4 = 9 water

Time: O(N)
Space: O(1)
*/

int trap(vector<int>& height) {
    if (height.size() < 3) {
    	return 0;
    }
    int left = 0, right = height.size() - 1; // 2 pointers
    int leftMax = 0, rightMax = 0; 
    int ans = 0;

    while (left < right) {
    	rightMax = max(rightMax, height[right]);
    	leftMax = max(leftMax, height[left]);
    	if (height[left] < height[right]) {
    		ans += leftMax - height[left++];
    	} else {
    		ans += rightMax - height[right--];
    	}
    }
    return ans;
}












