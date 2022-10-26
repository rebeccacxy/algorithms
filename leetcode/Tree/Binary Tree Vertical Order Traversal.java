/*
Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

-----------------------------------------------------------------------

Edge case: Empty tree, return empty list.

Nodes should be ordered by column first, and nodes on the same column should be ordered vertically based on their row indices. 

Use BFS. Let BFS handle the depth ordering (for the same col, top comes first) and left to right ordering for us (insert left node to the queue first). Need to track of minimum position that has occurred, so we can traverse through the map. At the end of BFS traversal, we have a hashmap containing nodes grouped by column, and for each group, they are ordered by row. 

Example: root = [3,9,20,null,null,15,7]
Add 3 to queue, put col as 0 and new arraylist. Then update the corresponding list with number 3. Left and right subtree is not null, so push left node with column index = -1, and right  node with column index = 1. Go through layer by layer and finally have map with key as column index and all the numbers top down on this column. Iterate through every index, put into res and return it. 


Output: [[9],[3,15],[20],[7]]

Time: O(N)
Space: O(N)
*/

public List<List<Integer>> verticalOrder(TreeNode root) {
	List<List<Integer>> res = new ArrayList<>();
	if (root == null) {
		return res;
	}

   // map's key is column, we assume the root column is zero, the left node will minus 1 ,and the right node will plus 1
	Map<Integer, ArrayList<Integer>> map = new HashMap<Integer, ArrayList<Integer>>();
	Queue<TreeNode> queue = new LinkedList<>();
    // use a HashMap to store the TreeNode and its column value
	Map<TreeNode, Integer> columns = new HashMap<TreeNode, Integer>();
	queue.offer(root);
	columns.put(root, 0);

	int min = 0; // = minimum column value (leftmost node)

	while (!queue.isEmpty()) {
		TreeNode node = queue.poll();
		int col = columns.get(node); 
		// If root has position col, then root.left has position col - 1 and root.right has position col + 1.
		
		if (!map.containsKey(col)) {
			map.put(col, new ArrayList<>());
		}
		map.get(col).add(node.val);
		if (node.left != null) {
			queue.add(node.left);
			columns.put(node.left, col - 1); // root.left
		} 
		if (node.right != null) {
			queue.add(node.right);
			columns.put(node.right, col + 1); // root.right
		}

		min = Math.min(min, col); // update min
	}

	while (map.containsKey(min)) {
		res.add(map.get(min++));
	}
	return res;
}













/*
Vertical Order Traversal of Binary Tree

Difference:
314. If two nodes are in the same row and column, the order should be from left to right.
987. If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.


Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

----------------------------------------------------------------------

BFS. Keep track of x and y of each coordinate. 
map = <col, <row, value>> 
map[0], {pair<0,1>}

1. Store all nodes in same column in ascending order
2. Sort those nodes according to row number

M columns N nodes
Time: O(N) for BFS, N*log(N/M) = Nlog(N) for sort
Space: O(N) + O(N) = O(N)
*/

struct NodeInfo {
    TreeNode* node;
    int row, col;
};

bool mySort(pair<int,int> a, pair<int,int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

class Solution {
public:
    // we need a col wise sorted list of nodes 
    // inside that we need row wise sorting in case of varying rows or value wise if same row
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>> > map; // <col, <row, value>>
        vector<vector<int>> res;
        
        queue<NodeInfo> q;
        q.push({root,0,0});
        while (!q.empty()) {
            TreeNode* curr = q.front().node;
            int x = q.front().row;
            int y = q.front().col;
            q.pop();
            
            map[y].push_back({curr->val, x});
            if (curr->left != NULL) {
                q.push({curr->left, x+1, y-1});
            }
            if (curr->right != NULL) {
                q.push({curr->right, x+1, y+1});
            }
        }
        for (auto z : map) {
            vector<pair<int,int>> t = z.second;
            sort(t.begin(),t.end(),mySort);
            vector<int> temp; // store all values into temp array and push that temp array into outer result at every iteration
            for (auto a : t) {
                temp.push_back(a.first);
            }
            res.push_back(temp);
            
        }                              
        return res;
    }
};








