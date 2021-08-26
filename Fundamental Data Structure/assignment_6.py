print("*******************************ASSIGNMENT 6***************************\n")

# Taking input of students
num=int(input("Please enter the number of students in the class "))
i=0
arr=[]
while i<num:
    print("Percentage obtained by roll no ",i+1," :",end=" ")
    marks=float(input())
    if marks>100 or marks<0:
        print("Please enter the valid response")
        continue
    arr.append(marks)
    i+=1


def bubbleSort(arr):
    n = len(arr)

    # Traverse through all array elements
    for i in range(n):
        swapped = False

        # Last i elements are already
        #  in place
        for j in range(0, n - i - 1):

            # traverse the array from 0 to
            # n-i-1. Swap if the element
            # found is greater than the
            # next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # IF no two elements were swapped
        # by inner loop, then break
        if swapped == False:
            break
        print("After ",i+1," wave of swapping :\n",arr)
    print("Final sorted list by bubble sort :",arr)
    print("Top 5 percentages are :")
    for i in range(-1, -6,-1):
        print(arr[i], end=" ")


def insertionSort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):

        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print("After ", i + 1, " wave of insertion :\n", arr)
    print("Final sorted list by insertion sort :", arr)
    print("Top 5 percentages are :")
    for i in range(-1, -6,-1):
        print(arr[i], end=" ")


def selection_sorting(arr):
    for i in range(len(arr)):

        # Find the minimum element in remaining
        # unsorted array
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j

        # Swap the found minimum element with
        # the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        print("After ", i + 1, " wave of selection sorting :\n", arr)
    print("Final sorted list by selection sort :", arr)
    print("Top 5 percentages are :")
    for i in range(-1, -6,-1):
        print(arr[i], end=" ")


def shellSort(arr):
    # Start with a big gap, then reduce the gap
    n = len(arr)
    gap = n // 2

    # Do a gapped insertion sort for this gap size.
    # The first gap elements a[0..gap-1] are already in gapped
    # order keep adding one more element until the entire array
    # is gap sorted
    while gap > 0:

        for i in range(gap, n):

            # add a[i] to the elements that have been gap sorted
            # save a[i] in temp and make a hole at position i
            temp = arr[i]

            # shift earlier gap-sorted elements up until the correct
            # location for a[i] is found
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

                # put temp (the original a[i]) in its correct location
            arr[j] = temp
        print("For gap equal to ", gap, " shell sort will be :\n", arr)
        gap //= 2
    print("Final sorted list by shell sort :", arr)
    print("Top 5 percentages are :")
    for i in range(-1, -6,-1):
        print(arr[i], end=" ")


print("\nSelection sort of given list of percentages are \n")
selection_sorting(arr)
print("****************************************************************************")
print("\nBubble sort of given list of percentages are \n")
bubbleSort(arr)
print("****************************************************************************")
print("\nInsertion sort of given list of percentages are \n")
insertionSort(arr)
print("****************************************************************************")
print("\nShell sort of given list of percentages are \n")
shellSort(arr)

