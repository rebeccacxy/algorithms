/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

-----------------------------------------------------------------------
Edge case: 
- Empty grid or single cell grid
- Start or end not accessible

BFS. Start in upper left corner, extend in 8 directions. Use a visited set to keep track of visited cells.

Time: O(N^2)
Space: O(N)
*/

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int res = 1;
    int row = grid.size();
    int col = grid[0].size();
    if (row == 0 || col == 0) { // edge case
        return -1;
    }
    if (grid[0][0] != 0 || grid[row-1][col-1] != 0) { // edge case
        return -1;
    }

    queue<pair<int, int>> queue;
    queue.push(make_pair(0,0)); // add starting point 
    vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}}; // 8 directions
    
    grid[0][0] = 1; // mark start as visited
    while (!queue.empty()) {
        pair<int, int> curr = queue.front();
        int x = curr.first, y = curr.second;
        if (x == row - 1 && y == col - 1) { // check if reach target
            return grid[x][y];
        }

        for (vector<int> direction : directions) {
            int neighbourX = x + direction[0];
            int neighbourY = y + direction[1];
            if (neighbourX >= 0 && neighbourX < row && neighbourY >= 0 && neighbourY < col && grid[neighbourX][neighbourY] == 0) {
                queue.push(make_pair(neighbourX, neighbourY));
                grid[neighbourX][neighbourY] = grid[x][y] + 1;
            }
        }
        queue.pop();
    }
    return -1;
}










