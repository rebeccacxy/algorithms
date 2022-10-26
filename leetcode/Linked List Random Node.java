/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

----------------------------------------------------------------------

Use Reservoir sampling, to do random sampling over a population of unknown size and constant space. 

Time: O(1) for constructor, O(N) for getRandom() where N = length of input list
Space: O(1)
*/

class Solution {
	ListNode head = null;

    public Solution(ListNode head) {
        this.head = head;
    }
    
    public int getRandom() {
        ListNode curr = this.head;
        int i = 1, ans = 0;
        while (curr != null) {
        	if (Math.random() * i < 1) {
        		ans = curr.val;
        	}
        	curr = curr.next;
        	i++;
        }
        return ans;
    }
}














