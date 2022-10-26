/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

----------------------------------------------------------------------

Can use heap – O(N log k) or Quickselect – O(N) avg. 

- Use hashmap to map element to its frequency. Array of unique elements but not unique frequencies. 
- Need only the most frequent k elements, so if ascending order, need elements at and beyond index N-k
- Select a pivot, partition the frequencies <= pivot on the left, frequencies > pivot on the right
- If pivot is at N-k index, return the right side of array.
- else if pivot_index < N-k, Quickselect(start, pivot_index - 1)
- else Quickselect(pivot_index + 1, end)

Time: O(N) avg, O(N^2) worst case
Space: O(N)
*/

// input: nums = [1,1,1,2,2,3], k = 2
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> map;
	for (int num : nums) {
		map[num]++;
	}

	vector<pair<int,int>> unique(map.begin(),map.end());
	int n = unique.size();
	vector<int> res;
	quickselect(unique, 0, n - 1, n - k);

	for (int i = n-k; i < n; i++) {
		res.push_back(unique[i].first);
	}

	return res;
}

void quickselect(vector<pair<int,int>>&unique, int start, int end, int k) {
	/*
    Sort a list within left..right till kth less frequent element takes its place. 
    */

    int pivot = unique[end].second; // 3 then 2
    int j = start;
    // move all less frequent elements to the left
    for (int i = start; i < end; i++) {
    	if (unique[i].second <= pivot) {
    		swap(unique[i], unique[j]);
    		j++;
    	}
    }

    swap(unique[end], unique[j]); // move pivot to final place

    // j = 2 then 1
    if (j == k) { // base case: list contains only one element
    	return;
    }

    if (j > k) {
    	return quickselect(unique, start, j-1, k); // go left
    } else {
    	return quickselect(unique, j+1, end, k); // go right
    }

}














