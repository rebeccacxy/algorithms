/*
Given two sparse vectors, compute their dot product.

Implement class SparseVector:
    SparseVector(nums) Initializes the object with the vector nums
    dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

----------------------------------------------------------------------

Two pointer method. 
Represent elements of a sparse vector as a list of <index, value> pairs. We use two pointers to iterate through the two vectors to calculate the dot product.

n = length of input array. L, L2 = no. of non-zero elements for two vectors

Time: O(n) for creating <index, value> pairs, O(L + L2) for calculating dot product
Space: O(L) for creating <index, value> non-zero pairs, O(1) for calculating dot product

Follow up: What if only one of the vectors is sparse?
Ans: Use indices of the sparse vector, binary search the indices in the second vector. Time = (l log N) where l = length of sparse vector, N = length of non-sparse vector.
*/

vector<pair<int, int>> v;  // {index, num};

SparseVector(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
    	if (nums[i]) {
    		v.push_back({i, nums[i]});    
    	}
	}
}

// Return the dotProduct of two sparse vectors
int dotProduct(SparseVector& vec) {
    int ans = 0;
    for (int i = 0, j = 0; i < v.size() && j < vec.v.size();) {
    	if (v[i].first == vec.v[j].first) { // if indexes are equal 
        	ans += v[i].second * vec.v[j].second; // multiply values
        	i++;
        	j++;
    	} else if (v[i].first < vec.v[j].first) {
        	i++;
    	} else {
        	j++;
    	}
	}

    return ans;
}




// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);









