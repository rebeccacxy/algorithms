/*
Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1. Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

----------------------------------------------------------------------

1. Group islands by changing 1s to their index and increment index. All islands in a group will have the same index. 
Explore every island using DFS, count its area, give it an island index and save the result to a <index, area> map. Grid elements are updated with their corresponding island index. Since the grid has elements 0 or 1. The island index is initialized with 2.
2. Loop every cell == 0, check its connected island index and calculate total islands area. The possible connected island index is stored in a set to remove duplicate index.

Example:
1 0 1 -> 2 0 3
0 1 1 -> 0 3 3
1 0 1 -> 4 0 3
Now, we traverse each 0 in the grid and find its adjacent group and add up their areas.
For the 0 at (0,1), we get area = m[2]+m[3]+1 = 1+4+1 = 6
For the 0 at (1,0), we get area = m[2]+m[3]+m[4]+1 = 1+4+1+1 = 7
Then add 1 to account for the converted island.

Time: O(N^2), where N = length and width of grid
Space: O(N^2), used in DFS by area
*/

int dfs(vector<vector<int>>& grid, int i, int j, int index) {
    int size = grid.size();
    if (i < 0 || i >= size || j < 0 || j >= size || grid[i][j] != 1) {
    	return 0;
    }
    grid[i][j] = index;
    int count = dfs(grid, i+1, j, index) + 
                dfs(grid, i-1, j, index) + 
                dfs(grid, i, j+1, index) + 
                dfs(grid, i, j-1, index);
    return count + 1;
}

void findNeighbours(vector<vector<int>>& grid, int i, int j, set<int>& s) {
	// finding adjacent island groups
    int size = grid.size();
    if (i > 0) {
    	s.insert(grid[i-1][j]);
    }
    if (j > 0) {
    	s.insert(grid[i][j-1]);
    }
    if (i < size-1) {
    	s.insert(grid[i+1][j]);
    }
    if (j < size-1) {
    	s.insert(grid[i][j+1]);
    }
} 

int largestIsland(vector<vector<int>>& grid) {
	int size = grid.size(), res = 0, index = 2, count; // count area
	unordered_map<int, int> area; // <index, area>
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (grid[i][j] == 1) {
				area[index] = dfs(grid, i, j, index);
				res = max(res, area[index++]);
				// if grid is one large island, find maximum island 
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (grid[i][j] == 0) {
				set<int> seen;
				findNeighbours(grid, i, j, seen);
				count = 1; // account for converted island
				for (int i : seen) {
					count += area[i];
				}
				res = max(res, count);
			}
		}
	}
	return res;
}

















