import numpy as np

def strassen(a, b):
    def next_power_of_2(n):
        return 1 if n == 0 else 2**(n - 1).bit_length()
    
    def pad_matrix(mat, shape):
        padded = np.zeros(shape, dtype=mat.dtype)
        padded[:mat.shape[0], :mat.shape[1]] = mat
        return padded
    
    def strassen_recursive(A, B):
        n = A.shape[0]
        if n == 1:
            return A * B
        
        mid = n // 2
        A11, A12, A21, A22 = A[:mid, :mid], A[:mid, mid:], A[mid:, :mid], A[mid:, mid:]
        B11, B12, B21, B22 = B[:mid, :mid], B[:mid, mid:], B[mid:, :mid], B[mid:, mid:]
        
        M1 = strassen_recursive(A11 + A22, B11 + B22)
        M2 = strassen_recursive(A21 + A22, B11)
        M3 = strassen_recursive(A11, B12 - B22)
        M4 = strassen_recursive(A22, B21 - B11)
        M5 = strassen_recursive(A11 + A12, B22)
        M6 = strassen_recursive(A21 - A11, B11 + B12)
        M7 = strassen_recursive(A12 - A22, B21 + B22)
        
        C11 = M1 + M4 - M5 + M7
        C12 = M3 + M5
        C21 = M2 + M4
        C22 = M1 - M2 + M3 + M6
        
        C = np.vstack((np.hstack((C11, C12)), np.hstack((C21, C22))))
        return C
    
    a, b = np.array(a), np.array(b)
    assert a.shape[1] == b.shape[0], "Matrix dimensions do not match for multiplication"
    
    new_size = next_power_of_2(max(a.shape + b.shape))
    A_pad = pad_matrix(a, (new_size, new_size))
    B_pad = pad_matrix(b, (new_size, new_size))
    
    C_pad = strassen_recursive(A_pad, B_pad)
    return C_pad[:a.shape[0], :b.shape[1]]

# Example Usage:
A = [[1, 2, 3], [4, 5, 6]]
B = [[7, 8], [9, 10], [11, 12]]
result = strassen(A, B)
print(result)
