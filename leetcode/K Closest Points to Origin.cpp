/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

---------------------------------------------------------------------

Edge case: 
- If square of sqrt root could overflow int32. But assume it would not overflow. 
- What if there are fewer points than k. Eg. there are only 4 points and they ask us to return 6
- If k = 0 or negative. don't need to worry.

k closest points --> Use heap. Can use min heap or max heap, but min heap takes up more space as it stores all array elements (costly for large element arrays. So use max heap to maintain just k elements. 

- Use a priority queue for storing maxheap 
- Want to maintain a max heap of size k. After adding new points, check if size of heap is greater than k. If it exceeds k, remove root element to maintain size of heap at k. 

Example: points = [[1,3],[-2,2]], k = 1
distance = 10,8
maxHeap size = 2 > 1 --> pop top element. Now maxHeap only has [-2,2]

Time: O(n log k)
Space: O(k) – k elements
*/

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> result(k);
    priority_queue<vector<int>> maxHeap;

    for (auto &p : points) {
        int x = p[0], y = p[1]; // x and y = coordinates of point p
        maxHeap.push({x*x + y*y, x, y}); // distance = 10, 8
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    for (int i = 0; i < k; i++) {
        vector<int> top = maxHeap.top();
        maxHeap.pop();
        result[i] = {top[1], top[2]};
    }
    
    return result;
}










