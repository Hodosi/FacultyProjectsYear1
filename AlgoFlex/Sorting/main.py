"""
-> sortări:
▪ sortare prin selecție (selection sort)
▪ sortare prin selecție directă (direct selection sort)
▪ sortare prin inserție (insertion sort)
▪ metoda bulelor (bubble sort)
▪ metoda bulelor direct (direct bubble sort)
▪ quicksort(quick sort recursive)
▪ quicksort(quick sort recursive one line)
▪ quicksort(quick sort recursive partition)
▪ merge sort
▪ bucket sort
▪ radix sort
▪ heap sort (heap sort out of place)
▪ heap sort (heap sort in place)
"""


# ▪ sortare prin selecție
def selectionSort(l):

    v = l[:]

    if len(v) <= 1:
        return v

    for i in range(0, len(v) - 1):
        ind = i
        for j in range(i + 1, len(v)):
            if v[ind] > v[j]:
                ind = j
        if ind > i:
            v[i], v[ind] = v[ind], v[i]

    return v


# ▪ sortare prin selecție directă
def directSelectionSort(l):

    v = l[:]

    if len(v) <= 1:
        return v

    for i in range(0, len(v) - 1):
        for j in range(i + 1, len(v)):
            if v[i] > v[j]:
                v[i], v[j] = v[j], v[i]

    return v


# ▪ sortare prin inserție
def insertionSort(l):

    v = l[:]

    if len(v) <= 1:
        return v

    for i in range(1, len(v)):
        ind = i - 1
        val = v[i]
        while v[ind] > val and ind >= 0:
            v[ind + 1] = v[ind]
            ind -= 1
        v[ind + 1] = val

    return v


# ▪ metoda bulelor
def bubbleSort(l):

    v = l[:]

    if len(v) <= 1:
        return v

    sortat = False
    while not sortat:
        sortat = True
        for i in range(0, len(v) - 1):
            if v[i] > v[i + 1]:
                v[i], v[i + 1] = v[i + 1], v[i]
                sortat = False

    return v


# ▪ metoda bulelor direct
def directBubbleSort(l):

    v = l[:]

    if len(v) <= 1:
        return v

    for j in range(1, len(v)):
        for i in range(0, len(v) - j):
            if v[i + 1] < v[i]:
                v[i], v[i + 1] = v[i + 1], v[i]

    return v


# ▪ quicksort
def quickSortRecursive(v):

    if len(v) <= 1:
        return v

    pivot = v.pop()
    stanga = quickSortRecursive([x for x in v if x < pivot])
    dreapta = quickSortRecursive([x for x in v if x >= pivot])

    return stanga + [pivot] + dreapta


# ▪ quicksort one line
def quickSortRecursiveOneLine(v):
    return [] if len(v) == 0 else quickSortRecursiveOneLine([x for x in v[1:] if x < v[0]]) + [v[0]] + quickSortRecursiveOneLine([x for x in v[1:] if x >= v[0]])


# ▪ quicksort recursive partition
def partition(v, start, end):

    left = start
    right = end
    pivot = v[left]

    while left < right:
        while v[right] >= pivot and left < right:
            right -= 1
        v[left] = v[right]
        while v[left] <= pivot and left < right:
            left += 1
        v[right] = v[left]
    v[left] = pivot

    return left


def quickSortRecursivePartition(v, start, end):

    pos = partition(v, start, end)

    if start < pos - 1:
        quickSortRecursivePartition(v, start, pos - 1)
    if pos + 1 < end:
        quickSortRecursivePartition(v, pos + 1, end)

    return v


# mergesort
def merge(v, left, right):

    mid = (left + right) // 2
    i = left
    j = mid + 1
    sortat = []

    while i <= mid and j <= right:
        if v[i] <= v[j]:
            sortat.append(v[i])
            i += 1
        else:
            sortat.append(v[j])
            j += 1

    while i <= mid:
        sortat.append(v[i])
        i += 1
    while j <= right:
        sortat.append(v[j])
        j += 1

    for i in range(left, right + 1):
        v[i] = sortat.pop(0)


def mergeSort(v, left, right):

    if left >= right:
        return

    mid = (left + right) // 2
    mergeSort(v, left, mid)
    mergeSort(v, mid + 1, right)

    merge(v, left, right)

    return v


def bucketSort(v, curent):

    bucket = [None]*10

    for value in v:
        position = value[curent]
        if bucket[position] == None:
            bucket[position] = [value]
        else:
            bucket[position].append(value)

    v.clear()
    for buck in bucket:
        if buck == None:
            continue
        for value in buck:
            v.append(value)

    return value


def radixSort(v, dim):

    for i in range(dim - 1, -1, -1):
        bucketSort(v, i)

    return v


def heapifyUp(v, pos):

    if len(v) <= 1:
        return v

    curent_position = pos
    parent_position = (curent_position - 1) // 2

    while curent_position > 0 and v[curent_position] < v[parent_position]:
        v[curent_position], v[parent_position] = v[parent_position], v[curent_position]
        curent_position = parent_position
        parent_position = (curent_position - 1) // 2


def heapifyDown(v, pos, limit):

    if limit <= 1:
        return v

    curent_position = pos
    left_child_position = curent_position * 2 + 1
    right_child_position = curent_position * 2 + 2

    child_position = None

    if right_child_position >= limit:
        child_position = left_child_position
    elif v[left_child_position] <= v[right_child_position]:
        child_position = left_child_position
    else:
        child_position = right_child_position

    while child_position < limit and v[curent_position] > v[child_position]:
        v[curent_position], v[child_position] = v[child_position], v[curent_position]
        curent_position = child_position
        left_child_position = curent_position * 2 + 1
        right_child_position = curent_position * 2 + 2
        if right_child_position >= limit:
            child_position = left_child_position
        elif v[left_child_position] <= v[right_child_position]:
            child_position = left_child_position
        else:
            child_position = right_child_position


def heapSortOutOfPlace(v):

    my_heap = []

    for value in v:
        my_heap.append(value)
        heapifyUp(my_heap, len(my_heap) - 1)

    v.clear()
    while len(my_heap):
        v.append(my_heap[0])
        my_heap[0] = my_heap[-1]
        my_heap.pop()
        heapifyDown(my_heap, 0, len(my_heap))

    return v


def heapSortInPlace(v):

    for i in range(len(v) // 2 - 1, -1, -1):
        heapifyDown(v, i, len(v))

    for limit in range(len(v) - 1, 0, -1):
        v[limit], v[0] = v[0], v[limit]
        heapifyDown(v, 0, limit)

    return v


def main():
    l = [6, 5, 3, -3, 54, 24, 32, -3, 3, 1, 32, 123, -4]
    print("selection sort:")
    print(selectionSort(l))
    print("direct selection sort:")
    print(directSelectionSort(l))
    print("insertion sort:")
    print(insertionSort(l))
    print("bubble sort:")
    print(bubbleSort(l))
    print("direct bubble sort:")
    print(directBubbleSort(l))
    v = l[:]
    print("quick sort recursive:")
    print(quickSortRecursive(v))
    v = l[:]
    print("quicksort recursive in one line:")
    print(quickSortRecursiveOneLine(v))
    v = l[:]
    print("quicksort recursive partition:")
    print(quickSortRecursivePartition(v, 0, len(v) - 1))
    v = l[:]
    print("merge sort:")
    print(mergeSort(v, 0, len(v) - 1))
    v = [(7, 4, 6), (5, 1, 5), (2, 4, 6), (2, 1, 4), (3, 2, 4)]
    dim = len(v[0])
    print("radix sort:")
    print(radixSort(v, dim))
    v = l[:]
    print("heap sort out of place:")
    print(heapSortOutOfPlace(v))
    v = l[:]
    print("heap sort in place:")
    print(heapSortInPlace(v))


main()