# Size of the table is created
size = int(input("Enter the size of the table "))
table_l = [["", -1] for i in range(size)]
table_q = [["", -1] for k in range(size)]

def key_gen(name):
    len_n = len(name)
    i = 0
    key = 0
    while i < len_n:
        key += ord(name[len_n - i - 1]) * (10 ** i)
        i = i + 1
    return key

def insert_linearprobing(name, number):
    j = 0
    key= key_gen(name)
    while True:
        if (table_l[(key + j) % size][1] == -1) or (table_l[(key + j) % size][1] == -2):
            table_l[(key + j) % size][1] = number
            table_l[(key + j) % size][0] = name
            if j==0:
                return "The " + str(name) + " is inserted at " + str(key % size) + " after comparing just one time "
            return "The " + str(name) + " is inserted at position " + str((key + j) % size) + " after " + str(
                j + 1) + " Comparisons"
        j += 1
        if j == size:
            return " The size is full\n"



def search_linearprobing(name):
    key= key_gen(name)
    if table_l[key % size][1] == -1:
        return "The given name{0} is not present in the table\n".format(str(name))

    else:
        j = 0
        while table_l[(key + j) % size][0] != name:
            j += 1
            if j == size:
                return "The given name is not present in the table\n "
        return str(name) + " is found at " + str((key + j) % size) + " position after " + str(
            j + 1) + " Comparison/s\nThe Phone number of " + str(name) + " is " + str(table_l[(key + j) % size][1])


def delete_linearprobing(name):
    key= key_gen(name)
    if table_l[key % size][1] == -1:
        return "The given name" + str(name) + " is not present in the table\n"
    if table_l[key % size][0] == name:
        table_l[key % size][0] = ''
        table_l[key % size][1] = -2
        return str(name) + " is deleted from " + str(
            key % size) + " position after just one comparison only\n"
    else:
        j = 1
        count = 1
        while table_l[(key + j) % size][0] != name:
            j += 1
            count += 1
            if count == size:
                return "The given element is not present in the table hence it cannot be deleted \n "
        table_l[(key + j) % size][0] = ''
        table_l[(key + j) % size][1] = -2

        return str(name) + " is deleted from " + str((key + j) % size) + " position after " + str(
            count + 1) + " Comparisons\n"


def insert_quadraticprobing(name, number):
    key= key_gen(name)
    if (table_q[key % size][1] == -1) or (table_q[key % size][1] == -2):
        table_q[key % size][0] = name
        table_q[key % size][1] = number
        return "The " + str(name) + " is inserted at " + str(key % size) + " after comparing just one time "
    else:
        j = 1
        count = 1
        while (table_q[(key + j * j) % size][1] != -1) and (table_q[(key + j * j) % size][1] != -2):
            j += 1
            count += 1
            if count == size:
                return " Couldn't Insert this element  \n"

        table_q[(key + j * j) % size][1] = number
        table_q[(key + j * j) % size][0] = name
        return "The " + str(name) + " is inserted at position " + str((key + j * j) % size) + " after " + str(
            count + 1) + " Comparisons"


def search_quadraticprobing(name):
    key= key_gen(name)
    if table_q[key % size][1] == -1:
        return "The given name is not present in the table\n"
    if table_q[key % size][0] == name:
        return str(name) + " is found at " + str(key % size) + " position with one comparison only\n"
    else:
        j = 1
        count = 1
        while table_q[(key + j * j) % size][0] != name:
            j += 1
            count += 1
            if count == size:
                return "The given element is not present in the table\n "
        return str(name) + " is found at " + str((key + j) % size) + " position after " + str(
            count + 1) + " Comparisons\nThe Phone number of " + str(name) + " is " + str(
            table_q[(key + j * j) % size][1])


def delete_quadraticprobing(name):
    key= key_gen(name)
    if table_q[key % size][1] == -1:
        return "The given name " + str(name) + " is not present in the table\n"
    if table_q[key % size][0] == name:
        table_q[key % size][0] = ''
        table_q[key % size][1] = -2
        return str(name) + " is deleted from " + str(
            key % size) + " position with just one comparison only\n"
    else:
        j = 1
        count = 1
        while table_q[(key + j * j) % size][0] != name:
            j += 1
            count += 1
            if count == size:
                return "The given element is not present in the table hence it cannot be deleted \n "
        table_q[(key + j) % size][0] = ''
        table_q[(key + j) % size][1] = -2

        return str(name) + " is deleted from " + str((key + j * j) % size) + " position after " + str(
            count + 1) + " Comparisons\n"


def choice():
    print("\t\tEnter your Choice ")
    print(" 1. To insert using linear probing ")
    print(" 2. To delete using linear probing ")
    print(" 3. To search using linear probing ")
    print(" 4. To insert using quadratic probing ")
    print(" 5. To delete using quadratic probing ")
    print(" 6. To search using quadratic probing ")
    print(" 0. To exit ")
    ch = int(input("YOUR CHOICE: "))
    return ch


def main():
    while True:
        chh = choice()
        if 1<=chh<7:
            nam = input("Enter Name: ")
        else:
            return "Thank you for using our Hashing method"
        if chh == 1:
            numb = int(input("Enter Number: "))
            print(insert_linearprobing(nam, numb))
            print(table_l)
        elif chh == 2:
            print(delete_linearprobing(nam))
            print(table_l)
        elif chh == 3:
            print(search_linearprobing(nam))
            print(table_l)
        elif chh == 4:
            numb = int(input("Enter Number: "))
            print(insert_quadraticprobing(nam, numb))
            print(table_q)
        elif chh == 5:
            print(delete_quadraticprobing(nam))
            print(table_q)
        elif chh == 6:
            print(search_quadraticprobing(nam))
            print(table_q)


main()
