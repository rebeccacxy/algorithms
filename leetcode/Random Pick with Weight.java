/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

    For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

----------------------------------------------------------------------

Edge case: 
- Empty weight array?
- One weight (length of w = 1)

Define an array of sum from 0 to current index.
sum[i] = sum(w[0] + ... + w[i])
random * sum(w) --> Do binary search within sum array

Example:
input: w = [1,3], prefixSum = [1,4], sum = 4

Let rand = 2.5, need to return index as 1
low = 0, high = 1, mid = 0
low = 1, high = 1, mid = 0

Let rand = 0.1 * 4 = 0.4
low = 0, high = 1, mid = 0 (mid < 1)
low = 0, high = 0, mid = 0 --> break while loop, return 0

Time: O(N) for constructor to construct prefix sums, O(log N) for binary search on prefix sums in pickIndex() 
Space: O(N) for constructor, O(1) for pickIndex()

https://leetcode.com/problems/random-pick-with-weight/discuss/1673932/Reservoir-Sampling-Approach
*/

class Solution {
    private int[] prefixSum;
    private int sum;

    public Solution(int[] w) {
        prefixSum = new int[w.length];
        sum = 0;
        for (int i = 0; i < w.length; i++) {
            sum += w[i];
            prefixSum[i] = sum;
        }
    }
    
    public int pickIndex() {
        int low = 0, high = prefixSum.length - 1;
        float rand = (new Random().nextFloat()) * sum; // generate random float between 0 and 1
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (rand > prefixSum[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}














