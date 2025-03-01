def binary_search(array, target, start=0, end=None):
    if end is None:
        end = len(array)
    
    while start < end:
        mid = (start + end) // 2
        if array[mid] == target:
            return (1, mid)
        elif array[mid] < target:
            start = mid + 1
        else:
            end = mid

    return (-1, start)

