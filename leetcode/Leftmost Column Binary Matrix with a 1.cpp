/*
A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

----------------------------------------------------------------------

Edge case: 
- No empty matrix

row = M, col = N
Brute force – O(M*N) = O(N^2).
Binary Search for each row – O(M*logN) 

Start from upper right corner, move down/left by one step each time.
Due to nature that each row is sorted in non-decreasing order,
if (mat[i][j] == 1) j - 1
else i + 1 // mat[i][j] == 0

Example: [[0,0],[1,1]]
row = 0, col = 1
mat[0][1] = 0 --> ++row
row = 1, col = 1
mat[1][1] = 1 --> --col
row = 1, col = 0
mat[1][0] = 1 --> --col
row = 1, col = -1 --> return 0

Time: O(N + M), where M = row, N = col
Space: O(1)
*/

int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
	int numRows = binaryMatrix.dimensions()[0];
	int numCols = binaryMatrix.dimensions()[1];

	// set pointers to top right corner
	int col = numCols - 1;
	int row = 0;

	while (col >= 0 && row < numRows) {
		if (binaryMatrix.get(row, col) == 1) {
			// move left by 1
			--col;
		} else {
			// move down by 1
			++row;
		}
	}
	// if never leave last column, all 0s
	return col == (numCols - 1) ? -1 : col + 1;
}














