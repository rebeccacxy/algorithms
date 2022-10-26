/*
There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

----------------------------------------------------------------------

Edge case: No empty array, so no edge case of length of input array = 0. 

Convert this problem into finding the next greater or equal element for each element in the array. If an element does not have a next greater or equal element, then the view is not blocked.

- Iterate through array from right to left, keep track of maximum value starting from right to current index. If current maximum is smaller than current position, add into final result, otherwise skip it. 

Time: O(N)
Space: O(1)
*/

// input: heights = [4,2,3,1]
vector<int> findBuildings(vector<int>& heights) {
	int maxHeight = -1;
	vector<int> buildings;

	for (int i = heights.size() - 1; i >= 0; i--) {
		if (heights[i] > maxHeight) { // if no building higher than or equal to current one to its right, push it into answer array
			maxHeight = heights[i]; // update current max building
			// maxHeight = 1,3,4
			buildings.push_back(i);
		}
	}

	// buildings = [3,2,0] --> reverse --> [0,2,3]
	reverse(buildings.begin(), buildings.end());
	return buildings;
}














