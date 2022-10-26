/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

---------------------------------------------------------------------

Can use DFS or BFS. BFS traverses level by level, DFS goes to leaves. Since we want to return a list of last element of all levels, BFS is the preferred approach here, and will perform better in terms of space complexity (complete tree for BFS vs skewed tree for DFS).

- Push root into the queue
- Pop out a node from the left
- Push left child into queue, then push right child

	1
2		3
pop out 1, add first left child and then right child

Time: O(N)
Space: O(N) = O(D) where D = tree diameter
*/

// input: root = [1,2,3,null,5,null,4]
vector<int> rightSideView(TreeNode* root) {
	vector<int> ans;
	if (root == NULL) { // base condition
		return ans;
	}
	queue<TreeNode*> nodequeue;
	nodequeue.push(root);
	while (!nodequeue.empty()) {
		int levelCount = nodequeue.size(); // current level length
		for (int i = 0; i < levelCount; i++) {
			TreeNode* curr = nodequeue.front(); 
			// curr = 1,2,3,5,4
			nodequeue.pop();
			if (i == levelCount - 1) { // if rightmost element (last node in current level), add it to ans
				ans.push_back(curr->val); 
				// curr->val = 1,3,4
			}
			if (curr->left != NULL) { // add left and right child nodes in queue
				nodequeue.push(curr->left);
			}
			if (curr->right != NULL) {
				nodequeue.push(curr->right);
			}
		}
	}
	return ans; // contains right side nodes
}




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */