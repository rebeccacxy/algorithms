/*
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

----------------------------------------------------------------------

Use DFS. Optimise – If root < left, skip whole left subtree. If root > right, skip right subtree. 

Example: root = [10,5,15,3,7,null,18], low = 7, high = 15
sum = 10
When visit left subtree, 5 < 7 -> visit right subtree
When root = 7 -> jump to second if branch, sum = 7, return 7. 
Go back to top, have 17 here.
Go to right subtree -> 15 within range, jump to second if branch. For left branch, root = null, for right branch, 18 > 15 -> out of range -> jump to else branch. Left subtree empty so return 15. 
17 + 15 = 32, return 32.

Time: O(N) where N = number of nodes
Space: O(N) = O(h) where h = height of tree
*/

int sum; 
int rangeSumBST(TreeNode* root, int left, int right) {
	sum = 0;
	dfs(root, left, right);
	return sum;
}

void dfs(TreeNode* root, int left, int right) {
	if (!root) { // base case
		return;
	}

	if (left <= root->val && root->val <= right) {
		sum += root->val;
	} else if (root->val > left) {
		dfs(root->left, left, right);
	} else { // root->val < right
		dfs(root->right, left, right);
	}
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







