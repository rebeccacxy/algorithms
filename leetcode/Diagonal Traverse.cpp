/*
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

-----------------------------------------------------------------------
Edge case: If matrix is empty, return empty array

One pass (one diagonal direction) sum of row and column index is equal 

Example: mat = 
[[1,2,3],
 [4,5,6],
 [7,8,9]]

 For (2,4) --> sum = 1
 For (3,5,7) --> sum = 2

1. Along any line parallel to the main diagonal, the sum of the coordinates is a constant (and increment by 1 each time we move to the next line)
2. We can use the parity of the sum of coordinates to determine the direction of traversal (going up or down)


Time: O(N^2) = O(MN)
Space: O(1)
*/


// input:  1 2 3
//		   4 5 6
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
	int numRow = mat.size();
	int numCol = mat[0].size();
	vector<int> diagonalTraverse(numRow * numCol);
	if (numRow == 0 || numCol == 0) {
		return diagonalTraverse;
	}

	bool upperRight = true;
	int iter = 0; // iterator to traverse diagonalTraverse
	for (int i = 0; i < (numRow + numCol - 1); i++) {
		if (upperRight) {
			int row = (i >= numRow) ? numRow - 1 : i; // row = 0
			while (row >= 0 && (i - row) < numCol) {
				diagonalTraverse[iter++] = mat[row][i - row];
				row--;
			} // row = -1 --> change direction to bottom left
		} else {
			int col = (i >= numCol) ? numCol - 1 : i; // i not >= numCol as i = 1 -> i = 1, col = 1

			// make sure row and col is not out of range
			// upper right --> decrease row number
			// bottom right --> decrease col number
			while (col >= 0 && (i - col) < numRow) { // if go this direction, will keep increasing numRow, decrease numCol
				diagonalTraverse[iter++] = mat[i - col][col]; // diagonalTraverse = [1, 2]
				--col;
			} // col = 0
		}
		upperRight = !upperRight; // change direction
	}
	return diagonalTraverse;
}


















