/*
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
































