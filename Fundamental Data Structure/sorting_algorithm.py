print("*******************************Sorting Algorithm***************************\n")

# Taking input of students
num = int(input("Please enter the number of students in the class "))
i = 0
arr = []
while i < num:
    print("Percentage obtained by roll no ", i + 1, " :", end=" ")
    marks = float(input())
    if marks > 100 or marks < 0:
        print("Please enter the valid response")
        continue
    arr.append(marks)
    i += 1
print()

def bucket_sort(key, arr, buc):
    val = 10 ** key
    for i in arr:
        buc[int((i // val) % 10)].append(i)
    index = 0
    for i in range(0, 10):
        while buc[i] != []:
            arr[index] = buc[i].pop(0)
            index += 1
    return arr


def radixSort(arr):
    buc = []
    for i in range(10):
        sub_buc = []
        buc.append(sub_buc)
    max_val = max(arr)
    no_key = 0
    while max_val != 0:
        max_val //= 10
        no_key += 1
    i = 0
    while i < no_key:
        arr = bucket_sort(i, arr, buc)
        print("for ", 10*i, " place of Bucket sorting :\n", arr)
        i += 1
    print("Final sorted list by Radix sort :", arr)
    print("Top 5 percentages are :")
    for i in range(-1, -6, -1):
        print(arr[i], end=" ")


def partition(array, start, end):
    pivot = array[start]
    low = start + 1
    high = end

    while True:

        while low <= high and array[high] >= pivot:
            high = high - 1

        while low <= high and array[low] <= pivot:
            low = low + 1

        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break

    array[start], array[high] = array[high], array[start]

    return high


# Function to do Quick sort
def quickSort(arr, low, high):
    if low < high:
        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)
        #Printing the recursion
        print("For index ",low,"-",high,"recursion is :\n",arr[low:high+1])
        # Separately sort elements before
        # partition and after partition
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)


# print("\nRadix sort of given list of percentages are \n")
# radixSort(arr)
quickSort(arr, 0, len(arr) - 1)
print("\nQuick sort of given list of percentages are \n",arr)
print("Top 5 percentages are :")
for i in range(-1, -6, -1):
    print(arr[i], end=" ")