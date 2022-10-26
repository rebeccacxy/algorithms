/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

-----------------------------------------------------------------------

Use modified Dijsktra approach. Want to find path with smallest max height. Start at (0,0), then iterate through surrounding squares and add them to priority queue, which stores <height, row, col>. Then mark as visited so we don't enter the same cell into pq more than once. Keep track of the largest value so far and repeat the process until reach the end cell.

Time: O(N^2 log N) where N = length of grid
Space: O(N^2)
*/

int swimInWater(vector<vector<int>>& grid) {
	int n = grid.size();
	int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; 
	int level = 0;

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({grid[0][0], 0, 0});
	vector<vector<bool>> visited(n, vector<bool> (n, false));
	visited[0][0] = true;

	while (!pq.empty()) {
		vector<int> curr = pq.top();
		pq.pop();
		int value = curr[0], row = curr[1], col = curr[2];
		level = max(level, grid[row][col]);
		if (row == n-1 and col == n-1) {
			break;
		}
		for (int d = 0; d < 4; d++) {
			int neighbourR = row + directions[d][0];
			int neighbourC = col + directions[d][1];
			if (neighbourR >= 0 and neighbourC >= 0 and neighbourR < n and neighbourC < n and !visited[neighbourR][neighbourC]) {
				visited[neighbourR][neighbourC] = true;
				pq.push({grid[neighbourR][neighbourC], neighbourR, neighbourC});
			}
		}
	} 
	return level;
}















