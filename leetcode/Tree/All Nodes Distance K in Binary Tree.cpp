/* 
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

-----------------------------------------------------------------------
Either BFS or DFS to find parent relationship for each node, and add into a separate map. Then do BFS from target node, layer by layer, to find all nodes distance K from target node. 

Do DFS then BFS. BFS on graph starting from target node to find all nodes of distance K from target. 

Example:
root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2

queue: [6,2,3] --> k = 1
extend 6 --> left and right child null, don't add into queue. 
5 is visited --> don't add into queue
2 --> add 7, 4
3 --> don't add parent, add 1 --> k-- --> k = 0

Time: O(N)
Space: O(N)
*/

void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeParent) {
    if (root == NULL) {
    	return;
    }
    if (root->left) {
        nodeParent.insert({root->left, root});
    }
    if(root->right) {
        nodeParent.insert({root->right, root});
    }
    dfs(root->left, nodeParent);
    dfs(root->right, nodeParent);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
	unordered_map<TreeNode*, TreeNode*> map; // {current, parent}
    queue<TreeNode*> queue;
    dfs(root, map);
    queue.push(target);
    vector<int> res;

    unordered_map<TreeNode*, bool> visited;
    while (!queue.empty()) {
		int len = queue.size();
        while (len--) {
            TreeNode* curr = queue.front(); 
            queue.pop();
            if (!k) {
            	res.push_back(curr->val);
            }
            visited[curr] = true;
            if(curr->left && !visited[curr->left]) {
                queue.push(curr->left);
            }
            if(curr->right && !visited[curr->right]) {
                queue.push(curr->right);
            }
            if(map.find(curr) != map.end() && visited[map[curr]] == false) {
                queue.push(map[curr]);
            }
        }
        k--;
        if (k < 0) {
        	break;
        }
    }
    return res;
}













