#import numpy
row = int(input("Enter no of rows:-"))
column = int(input("Enter no of columns:-"))
print("Enter element as Eg:- 1,2,3")
matrix = []
i = 0
while i < row:
    print("Enter elements in row:-", i + 1)
    lis = list(map(int, input().split(",")))
    if len(lis) != column:
        print("Please enter valid response")
        continue
    matrix.append(lis)
    i += 1
print("Your matrix is:-")
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        print("[", matrix[i][j], "]", end=" ")
    print()
# Now we have 6 objectives

# a) Check whether given matrix is upper triangular or not

if row == column:
    flag = True
    for r in range(1,len(matrix)):
        for c in range(r):
            if matrix[r][c] != 0:
                flag = False
                break
        if flag==False:
            break
    if flag == True:
        print("\nIt is an upper triangular matrix\n")
    if flag == False:
        print("\nIt is not an upper triangular matrix\n")
else:
    print("\nIt is not a square matrix so we cannot check upper triangular ")

# b) Compute summation of diagonal elements

if row==column:
    add = 0
    add1 =0
    for i in range(len(matrix)):
        add += matrix[i][i]
        add1 += matrix[i][len(matrix)-i-1]
    print("\nsummation of primary diagonal elements is:", add)
    print("summation of secondary diagonal elements is:", add1,"\n")
else:
    print("It is not a square matrix so sumation of diagonal is not possible")

# c) Compute transpose of matrix


transponse_matrix=[]
for r in range(len(matrix[0])):
    lis1=[]
    for j in range(len(matrix)):
        lis1.append(matrix[j][r])
    transponse_matrix.append(lis1)
print("\nTranspose of your matrix is:-")
for i in transponse_matrix:
    print(i)


#transponse_matrix =numpy.transpose(matrix)
#print("The transpose matrix is:-\n", transponse_matrix)

# d) Add and multiply two matrices

if row==column:
    matrix_sum=[]
    for i in range(len(matrix)):
        lis2=[]
        for j in range(len(matrix[i])):
            lis2.append(matrix[i][j]+transponse_matrix[i][j])
        matrix_sum.append(lis2)
    print("\nSum of matrix and it's transpose is")
    for i in matrix_sum:
        print(i)
else:
    print("\nIt is not a square matrix so Sum of matrix and it's transpose is not possible")

matrix_multiply=[]
for i in range(len(matrix)):
    mul=[]
    for k in range(len(matrix)):
        add2=0
        for j in range(len(matrix[i])):
            add2+=(matrix[i][j]*transponse_matrix[j][k])
        mul.append(add2)
    matrix_multiply.append(mul)
print("\nMultiply of matrix and it's transpose is")
for i in matrix_multiply:
    print(i)

# matrix_sum=numpy.add(matrix,transponse_matrix)
# print("Sum of matrix and it's transpose is\n",matrix_sum)
# matrix_multiply=numpy.multiply(matrix,transponse_matrix)
# print("Multiply of matrix and it's transpose is\n",matrix_multiply)

# e)determines the location of a saddle point if one exists.

lis3=[]
for i in range(len(matrix)):
    less=matrix[i][0]
    num = 0
    for j in range(len(matrix[i])):
        if less>matrix[i][j]:
            less=matrix[i][j]
            num=j
    lis3.append(num)
R=0
for c in lis3:
    flag2 = True
    for r in range(len(matrix)):
        if matrix[R][c]<matrix[r][c]:
            R+=1
            flag2=False
            break
    if flag2==False:
        continue
    else:
        print("\n",matrix[R][c],"is the saddle point\n","Row:",R,"Column:",c,"\n")
        break
if flag2==False:
    print("\nThis matrix does not have saddle point\n")

# f)Check if its magic square

if row == column:
    output = []
    def remove_Nestings(matrix):
        for i in matrix:
            if type(i) == list:
                remove_Nestings(i)
            else:
                output.append(i)
    remove_Nestings(matrix)
    output.sort()
    if row==column:
        add2=sum(matrix[0])
        flag3=True
        for i in range(len(matrix)):
            if add2!=sum(matrix[i]) or add2!=sum(transponse_matrix[i]) or add2!=add or add2!=add1:
                flag3=False
                break
        if output!=list(range(1,len(matrix)**2+1)):
            if flag3==True:
                print("\nIt is a non-normal magic square")
            flag3=False
        if flag3==True:
            print("\nIt is a magic square\n")
        else:
            print("\nIt is not a magic square\n")
else:
    print("It is not a square matrix so we cannot check magic square")
