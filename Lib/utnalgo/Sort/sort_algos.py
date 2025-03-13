def selection_sort(arr, reversed=False):
    n = len(arr)
    for i in range(n - 1):
        ext_idx = i
        for j in range(i + 1, n):
            if (arr[j] < arr[ext_idx]) ^ reversed:
                ext_idx = j
        if ext_idx != i:  
            arr[i], arr[ext_idx] = arr[ext_idx], arr[i]
    return arr  

def bubble_sort(arr, reversed=False):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if (arr[j] > arr[j + 1]) ^ reversed: 
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:  
            break
    return arr  


def insertion_sort(arr, reversed=False):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and (arr[j] > key) ^ reversed: 
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key  
    return arr  

def counting_sort(arr, exp, reversed=False):
    n = len(arr)
    output = [0] * n
    count = [0] * 10  

    for num in arr:
        index = (num // exp) % 10
        count[index] += 1

    if reversed:
        for i in range(8, -1, -1):
            count[i] += count[i + 1]
    else:
        for i in range(1, 10):
            count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1

    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr, reversed=False):
    if not arr:
        return arr

    max_val = max(arr)
    exp = 1

    while max_val // exp > 0:
        counting_sort(arr, exp, reversed)
        exp *= 10

    return arr  

def quick_sort(arr, reversed=False):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]  
    left = [x for x in arr if (x < pivot) ^ reversed]  
    middle = [x for x in arr if x == pivot]  
    right = [x for x in arr if (x > pivot) ^ reversed]  

    return quick_sort(left, reversed) + middle + quick_sort(right, reversed)


def merge_sort(arr, reversed=False):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort(arr[:mid], reversed)
    right = merge_sort(arr[mid:], reversed)

    return merge(left, right, reversed)

def merge(left, right, reversed):
    sorted_arr = []
    i = j = 0

    while i < len(left) and j < len(right):
        if (left[i] < right[j]) ^ reversed:  
            sorted_arr.append(left[i])
            i += 1
        else:
            sorted_arr.append(right[j])
            j += 1

    sorted_arr.extend(left[i:])
    sorted_arr.extend(right[j:])
    
    return sorted_arr


def bucket_sort(arr, reversed=False, bucket_size=5):
    if len(arr) == 0:
        return arr

    min_val, max_val = min(arr), max(arr)
    bucket_count = (max_val - min_val) // bucket_size + 1
    buckets = [[] for _ in range(bucket_count)]

    for num in arr:
        index = (num - min_val) // bucket_size
        buckets[index].append(num)

    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(sorted(bucket, reverse=reversed)) 

    return sorted_arr


def heapify(arr, n, i, reversed):
    largest = i 
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and (arr[left] > arr[largest]) ^ reversed:
        largest = left
    if right < n and (arr[right] > arr[largest]) ^ reversed:
        largest = right

    if largest != i: 
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest, reversed)

def heap_sort(arr, reversed=False):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i, reversed)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  
        heapify(arr, i, 0, reversed)  

    return arr 


def shell_sort(arr, reversed=False):
    n = len(arr)
    gap = n // 2  

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i

            while j >= gap and (arr[j - gap] > temp) ^ reversed:
                arr[j] = arr[j - gap]
                j -= gap

            arr[j] = temp

        gap //= 2  

    return arr

def insertion_sort_for_tim(arr, left, right, reversed):
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and (arr[j] > key) ^ reversed:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge_for_tim(arr, left, mid, right, reversed):
    left_part = arr[left:mid + 1]
    right_part = arr[mid + 1:right + 1]

    i = j = 0
    k = left

    while i < len(left_part) and j < len(right_part):
        if (left_part[i] < right_part[j]) ^ reversed:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1
        k += 1

    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1

def tim_sort(arr, reversed=False):
    n = len(arr)
    RUN = 32  

    for i in range(0, n, RUN):
        insertion_sort_for_tim(arr, i, min(i + RUN - 1, n - 1), reversed)

    size = RUN
    while size < n:
        for left in range(0, n, 2 * size):
            mid = min(n - 1, left + size - 1)
            right = min((left + 2 * size - 1), (n - 1))
            if mid < right:
                merge_for_tim(arr, left, mid, right, reversed)
        size *= 2

    return arr


def cocktail_shaker_sort(arr, reversed=False):
    n = len(arr)
    start = 0
    end = n - 1
    swapped = True  

    while swapped:
        swapped = False

        for i in range(start, end):
            if (arr[i] > arr[i + 1]) ^ reversed:  
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        if not swapped:  
            break
        swapped = False  
        end -= 1  

        for i in range(end - 1, start - 1, -1):
            if (arr[i] > arr[i + 1]) ^ reversed:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True

        start += 1  

    return arr


def comb_sort(arr, reversed=False):
    n = len(arr)
    gap = n  
    shrink_factor = 1.3  
    swapped = True  

    while gap > 1 or swapped:
        gap = max(1, int(gap / shrink_factor))  
        swapped = False  

        for i in range(n - gap):
            if (arr[i] > arr[i + gap]) ^ reversed:  
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True  

    return arr


def gnome_sort(arr, reversed=False):
    n = len(arr)
    index = 0

    while index < n:
        if index == 0 or (arr[index] >= arr[index - 1]) ^ reversed:
            index += 1  
        else:
            arr[index], arr[index - 1] = arr[index - 1], arr[index]  
            index -= 1  

    return arr

def counting_sort(arr, reversed=False):
    if not arr:
        return arr  

    min_val = min(arr)
    max_val = max(arr)
    range_of_values = max_val - min_val + 1  

    count = [0] * range_of_values  
    output = [0] * len(arr)  

    for num in arr:
        count[num - min_val] += 1  

    if reversed:
        for i in range(range_of_values - 2, -1, -1):
            count[i] += count[i + 1]  
    else:
        for i in range(1, range_of_values):
            count[i] += count[i - 1]  

    for i in range(len(arr) - 1, -1, -1):
        num = arr[i]
        output[count[num - min_val] - 1] = num  
        count[num - min_val] -= 1  

    return output  


def cycle_sort(arr, reversed=False):
    n = len(arr)

    for cycle_start in range(n - 1):
        item = arr[cycle_start]
        pos = cycle_start

        for i in range(cycle_start + 1, n):
            if (arr[i] < item) ^ reversed:
                pos += 1  

        if pos == cycle_start:
            continue  

        while item == arr[pos]:
            pos += 1  
        arr[pos], item = item, arr[pos]  

        while pos != cycle_start:
            pos = cycle_start

            for i in range(cycle_start + 1, n):
                if (arr[i] < item) ^ reversed:
                    pos += 1  

            while item == arr[pos]:
                pos += 1  
            arr[pos], item = item, arr[pos]  

    return arr  


def pigeonhole_sort(arr, reversed=False):
    if not arr:
        return arr  

    min_val, max_val = min(arr), max(arr)
    range_of_values = max_val - min_val + 1  

    holes = [[] for _ in range(range_of_values)]  

    for num in arr:
        holes[num - min_val].append(num)  

    sorted_arr = []
    if reversed:
        for i in range(len(holes) - 1, -1, -1):
            sorted_arr.extend(holes[i])
    else:
        for i in range(len(holes)):
            sorted_arr.extend(holes[i])

    return sorted_arr  


