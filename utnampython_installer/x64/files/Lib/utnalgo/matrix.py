def strassen(a, b):
    def next_power_of_2(n):
        return 1 if n == 0 else 2**(n - 1).bit_length()
    
    def pad_matrix(mat, shape):
        rows, cols = shape
        padded = [[0] * cols for _ in range(rows)]
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                padded[i][j] = mat[i][j]
        return padded
    
    def add_matrix(A, B):
        return [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]
    
    def sub_matrix(A, B):
        return [[A[i][j] - B[i][j] for j in range(len(A[0]))] for i in range(len(A))]
    
    def split_matrix(mat):
        mid = len(mat) // 2
        A11 = [row[:mid] for row in mat[:mid]]
        A12 = [row[mid:] for row in mat[:mid]]
        A21 = [row[:mid] for row in mat[mid:]]
        A22 = [row[mid:] for row in mat[mid:]]
        return A11, A12, A21, A22
    
    def merge_matrix(C11, C12, C21, C22):
        top = [C11[i] + C12[i] for i in range(len(C11))]
        bottom = [C21[i] + C22[i] for i in range(len(C21))]
        return top + bottom
    
    def strassen_recursive(A, B):
        n = len(A)
        if n == 1:
            return [[A[0][0] * B[0][0]]]
        
        A11, A12, A21, A22 = split_matrix(A)
        B11, B12, B21, B22 = split_matrix(B)
        
        M1 = strassen_recursive(add_matrix(A11, A22), add_matrix(B11, B22))
        M2 = strassen_recursive(add_matrix(A21, A22), B11)
        M3 = strassen_recursive(A11, sub_matrix(B12, B22))
        M4 = strassen_recursive(A22, sub_matrix(B21, B11))
        M5 = strassen_recursive(add_matrix(A11, A12), B22)
        M6 = strassen_recursive(sub_matrix(A21, A11), add_matrix(B11, B12))
        M7 = strassen_recursive(sub_matrix(A12, A22), add_matrix(B21, B22))
        
        C11 = add_matrix(sub_matrix(add_matrix(M1, M4), M5), M7)
        C12 = add_matrix(M3, M5)
        C21 = add_matrix(M2, M4)
        C22 = add_matrix(sub_matrix(add_matrix(M1, M3), M2), M6)
        
        return merge_matrix(C11, C12, C21, C22)
    
    assert len(a[0]) == len(b), "Matrix dimensions do not match for multiplication"
    
    new_size = next_power_of_2(max(len(a), len(a[0]), len(b[0])))
    A_pad = pad_matrix(a, (new_size, new_size))
    B_pad = pad_matrix(b, (new_size, new_size))
    
    C_pad = strassen_recursive(A_pad, B_pad)
    return [row[:len(b[0])] for row in C_pad[:len(a)]]

