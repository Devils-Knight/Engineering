print("*******************************Counting Sort***************************\n")

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
print("\n")

def countingSort(arr, exp1):
    n = len(arr)
    output = [0] * (n)
    count = [0] * (10)

    # Store count of occurrences
    for i in range(0, n):
        index = int((arr[i] // exp1))
        count[(index) % 10] += 1

    # adding indexes of previous number
    for i in range(1, 10):
        count[i] += count[i - 1]
        # Build the output array
    count.insert(0,0)
    count.pop(-1)
    i = 0
    while i <= n-1:
        index = int((arr[i] // exp1))
        output[count[(index) % 10]] = arr[i]
        count[(index) % 10] += 1
        i += 1

    # Copying the output array to arr[],
    i = 0
    for i in range(0, len(arr)):
        arr[i] = output[i]
    return arr

def radixSort(arr):
    # Find the maximum number to know number of digits
    max1 = max(arr)
    key = 1
    while max1 != 0:
        max1//=key
        sort=countingSort(arr, key)
        print("counting sorting for ",key," place will be:\n",sort)
        key *= 10
    print("\nFinal sorted list will be:\n",arr)


radixSort(arr)