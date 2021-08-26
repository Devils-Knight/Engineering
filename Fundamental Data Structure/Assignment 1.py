'''This code works on the input given by users about
    1.>Total studets
    2.>marks of each student
 then it interpretates 4 Results
    1.>finding average
    2.>maximum frequency
    3.>maximum and minimum marks
    4.>passing percentage of students'''


print('Assignment 1 of FDS\n    by Shubham malik \n\n')



total_students=int(input('Enter number of students in class '))

M=[] #marks of students
print('Enter marks obtained by students out of 100\nIf student is absent please enter ab ')

while len(M)<total_students:
    a=input()
    if a=='ab':
        M.append(-1)
        continue
    if int(a)>100:
        print('Please enter valid response')
        continue
    M.append(int(a))
print("The data is:",M,'\nAbsent students are represented by (-1)\n')





#finding avg
total_marks = 0
total_students_present = 0      #present students
absent = 0

for i in M:
    if i>=0 and i<=100:
        total_marks += i
        total_students_present += 1
    else:
        absent += 1

print('Total students present:',total_students,'\n')       

print('Total absentees:',absent,'\n')              #no of Absent students

print("Average Mark of students:",(total_marks/total_students_present),'\n')      #Avg marks of students





#finding max frequency

rang = [0]*101
for i in M:
    if i>=0 and i<101:
        rang[i] += 1
        
freq = 1
num =[]     #list of maximum occuring numbers
b = -1
for i in rang:
    b += 1
    if i>1:
        freq = i
        num.append(b)
if freq == 1:
    print('everyone has different marks.\n') #every marks occur only once
else:
    for i in num : 
        print(i,end=' ')
    print('marks are obtained by',freq,'students.\n')       #Highest frequency






#finding max and min marks

maxi = None
mini = None
for i in M:
    if i>=0 and i<101:
        if maxi is None or i>maxi:
            maxi = i
        if mini is None or i<mini:
            mini = i

print('Maximum marks obtained are:',maxi,'\n')  #max marks obtained

print('Minimum marks obtained are:',mini,'\n')    #min marks obtained








#Passing percentage ( Pass marks = 35)
passed_students = 0
for i in M:
    if i>=0 and i<101 and i>=35:
        passed_students += 1

print("Passing Percentage is: ",(passed_students/total_students_present)*100)        
        


