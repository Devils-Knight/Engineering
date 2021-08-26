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


def choice():
    chh = -1
    print("1. For inserting an element inside table using without replacement method ")
    print("2. For searching an element inside table using without replacement method ")
    print("Any other number to exit")
    chh = int(input("Enter your choice: "))
    return chh

def main():
    ch = choice()
    while ch == 1 or ch == 2:
        val= int(input("Enter the number: "))
        if ch == 1:
            print(without_replacement_insert(val))
            print(table)
        else:
            print(without_replacement_search(val))
            print(table)
        ch = choice()

main()


