/*
You are given an m x n grid rooms initialized with these three possible values.
    -1 A wall or an obstacle.
    0 A gate.
    INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

-----------------------------------------------------------------------
Edge case: Empty matrix?

Use BFS. Do BFS from all gates simultaneously. Mark all adjacent rooms as 1 distance away from gate. Everytime expand one layer, find all rooms 1 distance away from a gate, then 2 distance from a gate... until all positions have been visited. Have a queue and insert all positions, at each step try to extend 4 directions and record distance. 

Since BFS guarantees we search all rooms of distance d before searching rooms of distance d + 1, the distance to an empty room must be the shortest.

Time: O(N^2) = O(row * col)
Space: O(N^2) = O(row * col)
*/

void wallsAndGates(vector<vector<int>>& rooms) {
    int row = rooms.size();
    if (row == 0) {
    	return;
    }
    int col = rooms[0].size();

    queue<pair<int,int>> canReach; // save all elements reachable
    vector<pair<int,int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < row; i++) {
    	for (int j = 0; j < col; j++) {
    		if (rooms[i][j] == 0) {
    			canReach.emplace(i, j);
    		}
    	}
    }

    if (canReach.empty()) {
    	return;
    }

    while (!canReach.empty()) {
    	// try to extend in 4 directions
    	pair<int,int> curr = canReach.front();
    	int r = curr.first, c = curr.second;
    	canReach.pop();

    	for (pair<int,int> direction : directions) {
    		int neighbourR = r + direction.first;
    		int neighbourC = c + direction.second;
    		if (neighbourR < 0 || neighbourC < 0 || neighbourR >= row || neighbourC >= col || rooms[neighbourR][neighbourC] <= rooms[r][c] + 1) {
    			continue;
    		}
    		rooms[neighbourR][neighbourC] = rooms[r][c] + 1;
    		canReach.emplace(neighbourR, neighbourC);
    	}
    }
}




// Facebook version

/*
Input:
_ W G _
_ _ _ W
_ W _ W
G W _ _

Output:
3 W G 1
2 2 1 W
1 W 2 W
G W 3 4
*/

void wallsAndGates(vector<vector<int>>& rooms) {
    int row = rooms.size();
    if (row == 0) {
    	return;
    }
    int col = rooms[0].size();

    queue<pair<int,int>> canReach; // save all elements reachable
    vector<pair<int,int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < row; i++) {
    	for (int j = 0; j < col; j++) {
    		if (rooms[i][j] == 'G') {
    			canReach.emplace(i, j);
    		}
    	}
    }

    if (canReach.empty()) {
    	return;
    }

    while (!canReach.empty()) {
    	// try to extend in 4 directions
    	pair<int,int> curr = canReach.front();
    	int r = curr.first, c = curr.second;
    	canReach.pop();

    	for (pair<int,int> direction : directions) {
    		int neighbourR = r + direction.first;
    		int neighbourC = c + direction.second;
    		if (neighbourR < 0 || neighbourC < 0 || neighbourR >= row || neighbourC >= col || rooms[neighbourR][neighbourC] <= rooms[r][c] + 1) {
    			continue;
    		}
    		if (rooms[neighbourR][neighbourC] == '_') {
    			rooms[neighbourR][neighbourC] = rooms[r][c] + 1;
    			canReach.emplace(neighbourR, neighbourC);
    		}
    	}
    }
}





