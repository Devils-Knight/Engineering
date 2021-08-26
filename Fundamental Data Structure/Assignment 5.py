input("***********************ASSIGNMENT 5**************************")
num=int(input("Enter no of students in class :\n"))
input("\nEnter the names and roll no's of present students in the following format\nEg>jetha_lal 69\n")
dic={}
fun=lambda key,value:dic.update({key:value})
for i in range(num):
    a=input().split(" ")
    fun(a[0],int(a[1]))
roll_no_list=list(dic.values())
roll_no_list.sort()
check=int(input("\nPlease enter the roll number of the student you want to check :"))

def get_key(val): 
    for key, value in dic.items(): 
         if val == value: 
             return key 

if check in roll_no_list:
    name=get_key(check)
    print("\nThe name of the roll number ",check," is ",name)


def linear_search(arr,n):
    for i in arr:
        if i==n:
            return 1
    return -1

input("\nlinear search result")
lin=linear_search(roll_no_list,check)
if lin!=-1:
    print("Roll number ",check," ",name," was present at the training program")
else:
    print("Roll number ",check," was absent at the training program")




def sentinelSearch(arr, x) :
    n=len(arr)  
    # Element to be searched is added at the last index  
    arr[n] = x  
    i = 0
    while (arr[i] != x) :  
        i += 1

    if i < n : 
        return 1
    else : 
        return -1
input("\nSentinel Search result")
senti=sentinelSearch(roll_no_list,check)
if senti!=-1:
    print("Roll number ",check," ",name," was present at the training program")
else:
    print("Roll number ",check," was absent at the training program")




def binary_search(arr, x): 
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
        mid = (high + low) // 2
        if arr[mid] < x: 
            low = mid + 1
        elif arr[mid] > x: 
            high = mid - 1
        else: 
            return 1
    return -1
input("\nBinary search result")
binar=binary_search(roll_no_list,check)
if binar!=-1:
    print("Roll number ",check," ",name," was present at the training program")
else:
    print("Roll number ",check," was absent at the training program")


def fibonaccianSearch(arr, x):
    n=len(arr)  
    fibMMm2 = 0 
    fibMMm1 = 1 
    fibM = fibMMm2 + fibMMm1 
    # Fibonacci Number greater than or equal to n  
    while (fibM < n): 
        fibMMm2 = fibMMm1 
        fibMMm1 = fibM 
        fibM = fibMMm2 + fibMMm1 
    # Marks the eliminated range from front 
    offset = -1
    # When fibM becomes 1, fibMm2 becomes 0  
    while (fibM > 1):   
        # Check if fibMm2 is a valid location 
        i = min(offset+fibMMm2, n-1) 
   
        if (arr[i] < x): 
            fibM = fibMMm1 
            fibMMm1 = fibMMm2 
            fibMMm2 = fibM - fibMMm1 
            offset = i 
  
        elif (arr[i] > x): 
            fibM = fibMMm2 
            fibMMm1 = fibMMm1 - fibMMm2 
            fibMMm2 = fibM - fibMMm1 

        else : 
            return 1
  
    # comparing the last element with x */ 
    if(fibMMm1 and arr[offset+1] == x): 
        return 1 
    # element not found. return -1  
    return -1
input("\nFabonacci search reult")
fabon=fibonaccianSearch(roll_no_list,check)
if fabon!=-1:
    print("Roll number ",check," ",name," was present at the training program")
else:
    print("Roll number ",check," was absent at the training program")