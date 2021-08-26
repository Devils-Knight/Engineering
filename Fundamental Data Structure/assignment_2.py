num=int(input("Enter number of students in the class "))
print("Enter the sports interrested by a student in the following format\n for cricket-c,for badminton-b,for football-f and for not any game-na\n if you like more than 1 game put \',\' b/w them ")
i=0
cricket=[]
badminton=[]
football=[]
not_interested=[]
while i<num:
    print("roll no ",i+1,end=" ")
    interest=list(map(str,input().split(",")))
    for _ in interest:
        if _=="c":
            cricket.append(i+1)
        elif _=="b":
            badminton.append(i+1)
        elif _=="f":
            football.append(i+1)
        elif _=="na":
            not_interested.append(i+1)
        else:
            print("Please enter valid response")
            i-=1
            break
    i+=1
cricket_and_badminton=[]
for i in cricket:
    if i in badminton:
        cricket_and_badminton.append(i)
print("List of roll no of students interested in both cricket and badminton is-->",cricket_and_badminton)
either_cricket_or_badminton_but_not_both=[]
cricket_or_badminton=list(set(cricket+badminton))
for i in cricket_or_badminton:
    if i not in cricket_and_badminton:
        either_cricket_or_badminton_but_not_both.append(i)
print("List of roll no of students interested in either cricket or badminton but not both-->",either_cricket_or_badminton_but_not_both)
neither_cricket_nor_badminton=num-len(cricket_or_badminton)
print("Number of students interested neither cricket nor badminton is ",neither_cricket_nor_badminton)
cricket_or_football=list(set(cricket+football))
cricket_and_football_but_not_badminton=[]
for i in cricket_or_football:
    if i not in badminton:
        cricket_and_football_but_not_badminton.append(i)
print("Number of students interested cricket and football but not badminton is ",len(cricket_and_football_but_not_badminton))        