def binary_search(array, target, start=0, end=None, descending=False):
    if end is None:
        end = len(array)
    
    while start < end:
        mid = (start + end) // 2

        if array[mid] == target:
            return (1, mid)

        if descending:
            if array[mid] < target:
                end = mid  # Move left
            else:
                start = mid + 1  # Move right
        else:
            if array[mid] < target:
                start = mid + 1  # Move right
            else:
                end = mid  # Move left

    return (0, start)



def interpolation_search(arr, target, descending=False):
    low, high = 0, len(arr) - 1

    while low <= high and ((arr[low] <= target <= arr[high]) if not descending else (arr[low] >= target >= arr[high])):
        if arr[low] == arr[high]:  # Prevent division by zero
            if arr[low] == target:
                return (1, low)
            else:
                return (0, low if (target < arr[low]) ^ descending else low + 1)

        # Compute the estimated position
        pos = low + ((target - arr[low]) * (high - low) // (arr[high] - arr[low]))

        # Ensure pos is within bounds
        if pos < low:
            return (0, low)
        elif pos > high:
            return (0, high + 1)

        if arr[pos] == target:
            return (1, pos)
        
        if (arr[pos] < target) ^ descending:
            low = pos + 1
        else:
            high = pos - 1

    return (0, low)  


def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return (1, i)  
        elif arr[i] > target:
            return (0, i)  

    return (0, len(arr)) 


def r_check(matrix, r_low, r_high, target):
    while r_low < r_high:
        mid_row = r_low + (r_high - r_low) // 2
        if matrix[mid_row][0] <= target <= matrix[mid_row][-1]:
            return mid_row
        elif matrix[mid_row][0] > target:
            r_high = mid_row
        else:
            r_low = mid_row + 1
    return r_low  # Return the row where the target should be

def c_check(matrix, check_row, c_low, c_high, target):
    while c_low < c_high:
        mid_col = c_low + (c_high - c_low) // 2
        if matrix[check_row][mid_col] == target:
            return (1, (check_row, mid_col))  # Found
        elif matrix[check_row][mid_col] > target:
            c_high = mid_col
        else:
            c_low = mid_col + 1
    return (0, (check_row, c_low))  # Not found, return expected position

def binary_search_2d(matrix, target):
    row, col = len(matrix), len(matrix[0])
    r_low, r_high = 0, row
    got_row = r_check(matrix, r_low, r_high, target)

    if got_row < row:  # Check if row is within bounds
        return c_check(matrix, got_row, 0, col, target)
    
    return (0, (got_row, 0)) 
