/*
LCA

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

-----------------------------------------------------------------------
Edge case: 
- If root is null, return null.
- If p or q = root, return root. Eg. If p = 7, q = 6, return 6

Base case: Compare p and q to curr node. If one in left, other in right subtree, then curr is LCA. 


Example: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
          6
    2          8
0      4    7     9
    3    5

2 cases:
- Both nodes on different branch (2, 8) --> traverse upwards and find parent (6)
- Both nodes on the same branch (2, 4) --> take ancestor node (2)

If p = 7, q = 9:
Start at root, now check that 7 > 6 and 9 > 6, so just search in right subtree. Know that 6 won't be LCA, but 8 might be LCA. Since 7 < 8, look in left subtree. 9 > 8, look in right subtree. Since 8 is were the split occurs, it is LCA. 


Use recursion. Search left and right subtree.
If encounter p or q, return it, and if left subtree return a pointer to node, could contain p or q, just return left subtree. Similar for the right subtree. If both left and right subtree return empty, then return root. 

Time: O(N) where N = no. of nodes. Visit every node in the tree. 
Space: O(N) = O(h), where h = height of tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) {
        return NULL;
    }
 
    if (root == p || root == q) {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL and right != NULL) {
        return root;
    }

    return left == NULL ? right : left;
}

/*
Example: root = [3,5,1,6,2,0,8,null,null,7,4]

            3
    5               1
6      2        0       8
    7     4

If p = 5, q = 4:
3->5->6 --> return none for left subtree
2->7->4 --> return q = 4
root = p = 5 so return root
3 will return left node (5) which is true

If p = 5, q = 1:
3->5 --> return p
3->1 --> return q
Because left and right subtree both not null, return root (3)


*/







/*
LCA III

Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).
Each node will have a reference to its PARENT node.

-----------------------------------------------------------------------

Time: O(N) = O(h1 + h2)
Space: O(1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

Node* lowestCommonAncestor(Node* p, Node* q) {
    Node* pCopy = p;
    Node* qCopy = q;
    int pDepth = 0, qDepth = 0;
    
    // find distance from the root
    while (pCopy->parent != NULL) {
        pCopy = pCopy->parent;
        pDepth++;
    }
    while (qCopy->parent != NULL) {
        qCopy = qCopy->parent;
        qDepth++;
    }
    
    // Put both pointers at the same depth
    while (qDepth > pDepth) {
        q = q->parent;
        qDepth--;
    }
    while (pDepth > qDepth) {
        p = p->parent;
        pDepth--;
    }
    
    // keep going to the next parent until you have the same parent
    while (p != q){
        p = p->parent;
        q = q->parent;
    }
    return p;
}









