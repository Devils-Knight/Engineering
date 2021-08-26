num_A=int(input("Please enter no of students in the class A "))
print("Enter pnr,date and month in this format\n Eg.)1,2,3")
valid_month_date=[31,28,31,30,31,30,31,31,30,31,30,31]
list_A=[]
n=0
while n<num_A:
    item_A = list(map(int,input().split(",")))
    if item_A[2]>12 or item_A[2]<1 :
        print("Please enter valid response")
        continue
    if item_A[1]>valid_month_date[(item_A[2]-1)] or item_A[1]<1:
        print("Please enter valid response")
        continue
    list_A.append(item_A)
    n+=1
num_B=int(input("Please enter no of students in the class B "))
print("Enter pnr,date and month in this format\n Eg.)1,2,3")
list_B=[]
m=0
while m<num_B:
    item_B = list(map(int,input().split(",")))
    if item_B[2]>12 or item_B[2]<1 :
        print("Please enter valid response")
        continue
    if item_B[1]>valid_month_date[(item_B[2]-1)] or item_B[1]<1:
        print("Please enter valid response")
        continue
    list_B.append(item_B)
    m+=1
List_SE_Comp_DOB=[]
i=0
j=0
while i<len(list_A) and j<len(list_B):
    if list_A[i][2]==list_B[j][2]:
        if list_A[i][1]<=list_B[j][1]:
            List_SE_Comp_DOB.append(list_A[i])
            i+=1
            continue
        else:
            List_SE_Comp_DOB.append(list_B[j])
            j+=1
            continue
    if list_A[i][2]<list_B[j][2]:
        List_SE_Comp_DOB.append(list_A[i])
        i+=1
        continue
    if list_A[i][2] > list_B[j][2]:
        List_SE_Comp_DOB.append(list_B[j])
        j+=1
        continue
while i<len(list_A):
    List_SE_Comp_DOB.append(list_A[i])
    i+=1
while j<len(list_B):
    List_SE_Comp_DOB.append(list_B[j])
    j+=1
months=['January','February','March','April','May','June','July','August','September','October','November','December']
for i in range (0,len(List_SE_Comp_DOB)):
    print('PNR =',List_SE_Comp_DOB[i][0],"  DOB =",List_SE_Comp_DOB[i][1],'of',months[(List_SE_Comp_DOB[i][2]-1)])
