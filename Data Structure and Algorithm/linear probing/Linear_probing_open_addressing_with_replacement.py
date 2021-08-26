size = int(input("Enter the size of the table "))
table = [[-1, -1] for i in range(size)]

def with_replacement_insert(element):
    value= element % size
    if table[value][0]==-1:
        table[value][0]=element
        return "The " + str(element) + " is inserted at position " + str(element % size) + " after comparing just one time"
    else:
        if table[value][0] % size == value:
            index = element % size
            count = 1
            while table[index][1] != -1:
                index = table[index][1]
                count += 1
            insert_index = index

            while table[insert_index][0] != -1:
                insert_index = (insert_index + 1) % size
                count += 1
                if count == size+1:
                    return "The size of table is full\n"
            table[insert_index][0] = element
            table[index][1] = insert_index
            return "The {0} is inserted at {1} after {2} comparisons ".format(element, insert_index, count + 1)
        else:
            count=1
            store_var = table[value]
            index= element % size

            while table[index][0] != -1:
                index= (index+1) % size
                count+=1
                if count == size+1:
                    return "The size is full\n"

            prev_index= store_var[0] % size
            while table[table[prev_index][1]] != store_var:
                prev_index=  table[prev_index][1]
            table[index][0] = store_var[0]
            table[index][1] = store_var[1]
            table[prev_index][1]= index
            table[value][0] = element
            table[value][1] = -1
            return "The {0} is inserted at position {1} after {2} comparisons".format(element, value, count+1)


def with_replacement_search(element) -> str:
    value= element % size
    if table[value][0] % size != value:
        return "This Element is not present in the given table"
    else:
        index= element % size
        count=1
        while table[index][1] != -1 and table[index][0] != element:

            count += 1
            if count == size + 1:
                return "The Element is absent \n"
            index = table[index][1]

        if table[index][0] == element:
            return "The Element {0} is found at position {1} after {2} comparisons ".format(element, index, count + 1)
        else:
            return "The Element {0} is not present in the table )".format(element)

def choice():
    print("\nEnter 1 for inserting value into the table")
    print("Enter 2 for searching value from the table")
    print("Enter any other kry to exit\n")
    ch= int(input("Enter your choice "))
    print()
    return ch

def main():
    chh= choice()
    while chh == 1 or chh == 2:
        ele = int(input("Enter the element "))
        if chh == 1:
            print(with_replacement_insert(ele))
            print(table)
        else:
            print(with_replacement_search(ele))
            print(table)
        chh= choice()

main()
