import numpy as np

def gaussian_determinant(matrix):
    """
    Calculates the determinant of a square matrix using Gaussian elimination.
    """
    # Create a floating-point copy of the matrix to avoid integer division issues
    A = np.array(matrix, dtype=float)
    n = A.shape[0]
    
    # Ensure the matrix is square
    if A.shape[0] != A.shape[1]:
        raise ValueError("The matrix must be square.")
        
    det = 1.0
    
    for i in range(n):
        # 1. Partial Pivoting: Find the row with the largest absolute value in column i
        pivot_row = i
        for r in range(i + 1, n):
            if abs(A[r, i]) > abs(A[pivot_row, i]):
                pivot_row = r
                
        # 2. Swap rows if necessary and flip the determinant sign
        if pivot_row != i:
            A[[i, pivot_row]] = A[[pivot_row, i]]
            det *= -1.0
            
        # 3. If the pivot element is zero, the matrix is singular (determinant is 0)
        if abs(A[i, i]) < 1e-12:
            return 0.0
            
        # 4. Eliminate elements below the pivot
        for r in range(i + 1, n):
            factor = A[r, i] / A[i, i]
            A[r, i:] -= factor * A[i, i:]
            
        # 5. Multiply the current diagonal element to the determinant
        det *= A[i, i]
        
    return det

# Example Usage:
matrix_example = [
    [2, 1, -1],
    [-3, -1, 2],
    [-2,  1, 2]
]

print("Calculated Determinant:", gaussian_determinant(matrix_example))
print("NumPy Built-in Verification:", np.linalg.det(matrix_example))
