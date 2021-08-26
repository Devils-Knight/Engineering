size = int(input("Enter the size of the table "))
table = [[-1, -1] for i in range(size)]

def without_replacement_insert(element):
    value = element % size
    if table[value][0] == -1:
        table[value][0] = element
        return "The " + str(element) + " is inserted at " + str(element % size) + " after comparing just one time "
    else:
        if table[element % size][0] % size == element % size:
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

        elif table[element % size][0] % size != element % size:
            index = element % size
            count = 1
            while table[index][0] != -1 and table[index][0] % size != element % size:
                index = (index + 1) % size
                count += 1
                if count == size + 1:
                    return "The size is full \n"
            if table[index][0] == -1:
                table[index][0] = element
                return f"The given {element} is inserted at {index} position after {count + 1} comparisons \n"
            else:
                while table[index][1] != -1:
                    index = table[index][1]
                insert_index = index
                while table[insert_index][0] != -1:
                    insert_index = (insert_index + 1) % size
                    count += 1
                    if count == size + 1:
                        return "The size of table is full\n"
                table[insert_index][0] = element
                table[index][1] = insert_index
                return "The given {0} is inserted at {1} position after {2} replacements \n".format(element,
                                                                                                    insert_index,
                                                                                                    count + 1)


def without_replacement_search(element):
    if table[element % size][0] % size == element % size:
        var = element % size
        count = 0
        while table[var][0] != element and table[var][1] != -1:
            var = table[var][1]
            count += 1
        if table[var][0] == element:
            return "Element {0} is found at position {1} after {2} comparisons \n".format(element, var, count + 1)
        elif table[var][1] == -1:
            return "This element is not present in the table \n"
    else:
        val = element % size
        count = 1
        while table[(val+count) % size][0] % size != element % size:
            count += 1
            if count == size + 1:
                return "Given element is not present in the table "
        val = (val+count) % size
        while table[val][0] != element and table[val][1] != -1:
            count += 1
            val = table[val][1]

        if table[val][0] == element:
            return "The element {0} is found at position {1} after {2} comparisons \n".format(element, val, count + 1)
        else:
            return "This element is not present in the table \n"


def choice_replacement():
    chh = -1
    print("1. For inserting an element inside table using without replacement method ")
    print("2. For searching an element inside table using without replacement method ")
    print("Any other number to exit")
    chh = int(input("Enter your choice: "))
    return chh




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
    print("\t\tLinear Probing\n")
    print("Enter 1 for Linear probing without replacement")
    print("Enter 2 for Linear Probing with replacement")
    method_choice=int(input("Enter your choice :"))
    if method_choice==1:
        ch = choice_replacement()
        while ch == 1 or ch == 2:
            val= int(input("Enter the number: "))
            if ch == 1:
                print(without_replacement_insert(val))
                print(table)
            else:
                print(without_replacement_search(val))
                print(table)
            ch = choice_replacement()

    elif method_choice==2:
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
    else:
        return 0
main()
