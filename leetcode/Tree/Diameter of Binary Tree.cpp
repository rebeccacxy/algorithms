/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

----------------------------------------------------------------------

Edge case: If root is null, return 0.

DFS problem. For a certain node, recursively find longest path on left subtree and right subtree. Sum of the longest path on the left and right for a node is the longest path for the node. 

Example: root = [1,2,3,4,5]
Initialise nodesOnLongestPath as 1.
Left child != null --> call dfs on 2, not leaf node --> call dfs on 4 --> return 1. Same for 5. Similarly, 3 will return 1. 
So nodesOnLongestPath = 2+1+1 = 4. return 4 - 1 = 3

Time: O(N) where N = num of nodes in tree
Space: O(N)
*/

int nodesOnLongestPath;

int depth(TreeNode* root) {
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	int leftDepth = 0;
	if (root->left != NULL) {
		// traverse left part
		leftDepth  = depth(root->left);
	}
	int rightDepth = 0;
	if (root->right != NULL) {
		rightDepth = depth(root->right);
	}
	nodesOnLongestPath = max(nodesOnLongestPath, leftDepth + rightDepth + 1);

	return 1 + max(rightDepth, leftDepth);
}


int diameterOfBinaryTree(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	nodesOnLongestPath = 1;
	depth(root);
	return nodesOnLongestPath - 1; // edges = nodes - 1
}
















