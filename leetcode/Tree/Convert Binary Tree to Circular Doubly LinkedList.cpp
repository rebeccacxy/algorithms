/*
Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

----------------------------------------------------------------------

Edge case: If number of nodes is 0 then return NULL.

Use DFS to traverse tree. In-place means mutating the input, so all changes are done on the given input. 

Initialise the head and tail nodes as NULL. Then use a helper function to recurse from the root. If the root is not null, then recurse on the left subtree. If the tail is not null, then link the tail and the current root. Else, set the head node to root. Finally mark the tail as the current root., and recurse on the right subtree. Then link the head and tail nodes to make it circular and return head.  

Example:
input: [4,2,5,1,3]
		4
	2		5
1		3

4->2->1(link 2 and 1)->3(link 3 and 2)->4(link 4 and 3)->5(link 5 and 4)->1(link 5 and 1 ie. head and tail nodes)

Time: O(N)
Space: O(N) – recursion stack of size of tree height. O(log N) best case of completely balanced tree and O(N) for worst case of unbalanced tree
*/


void dfs(Node* root, Node*& head, Node*& tail) {
    if (!root) {
    	return;
    }
    dfs(root->left, head, tail);     
    if (!head) { // find the leftmost as head
        head = root;
    } else { // when head is found, link with tail
        root->left = tail;
        tail->right = root; 
    }
    tail = root;
    dfs(root->right, head, tail);
}

Node* treeToDoublyList(Node* root) {
	Node* head = nullptr;
	Node* tail = nullptr;

    if (!root) {
    	return NULL;
    }
    dfs(root, head, tail);
    head->left = tail;
    tail->right = head;
    return head;
}





