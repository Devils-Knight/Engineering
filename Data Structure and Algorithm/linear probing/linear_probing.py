def calc_hash(a, ts):
    return a % ts


def insert(d, ht):
    h = calc_hash(d, n)
    p = h
    for j in range(n):
        if ht[p][0] == -1:
            ht[p][0] = d
            print("\nInserted data ,", d, " at position ", p, " successfully\n")
            return 0
        elif calc_hash(ht[p][0], n) == h:
            i = p
            for k in range(n):
                if ht[i][1] == -1:
                    break
                i = ht[i][1]
            ni = i
            for k in range(n):
                ni += 1
                ni %= n
                if ht[ni][0] == -1:
                    ht[ni][0] = d
                    ht[i][1] = ni
                    print("\nInserted data ,",d," at position ",ni," successfully\n")
                    return 0
            print("\nNo empty space found \n")
            return 0
        else:
            p += 1
            p %= n
    print("\nNo empty space found\n")


def search(d, ht):
    h = calc_hash(d, n)
    p = h
    noc = 0
    for j in range(n):
        if ht[p][0] == d:
            noc += 1
            print("\nElement found at , ", p,"Number of Comparisons : ",noc, "\n")
            return 0
        elif calc_hash(ht[p][0], n) == h:
            for i in range(n):
                p = ht[p][1]
                noc += 1
                if ht[p][0] == d:
                    noc+=1
                    print("\nFound at position ",p,"Number of Comparisons : ",noc,"\n")
                    return 0
            print("\nNot found \n")
            return 0
        else:
            noc += 1
            p += 1
            p %= n
    print("\nNot found\n")


def get_data():
    ch = 0
    while ch != 4:
        ch = int(input("1.Enter data\n2.Search\n3.Print Table\n4.Exit"))
        if ch == 1:
            d = int(input("Enter data: "))
            insert(d, ht)
        elif ch == 2:
            d = int(input("Enter element to be searched: "))
            search(d, ht)
        elif ch == 3:
            count = 0
            print()
            for i in ht:
                if i[0] != -1:
                    print(count, ".", i[0], "Chain", i[1])
                count += 1
            print()
        else:
            pass


ht = []
n = 10
for i in range(n):
    row = [-1, -1]
    ht.append(row)
get_data()


def calc_hash(a, ts):
    return a % ts


def del_element(d,ht):
    h = calc_hash(d,n)
    p = h
    m = h
    if ht[h][0] == -1:
        print("\nHash Table is empty \n")
        return 0
    elif calc_hash(ht[h][0],n) == h:
        k = 0
        z = h
        for i in range(n):
            if ht[h][0] == d:
                print("\nElement ",d," at position : ",h," deleted\n")
                ht[h][0] = -1
                ht[h][1] = -1
                k=1
                break
            h = ht[h][1]
            if i != 0:
                z = ht[z][1]
        if k == 1:
            ht[z][1] = -1
        else:
            print("\nElement not found\n")
            return 0


def insert(d, ht):
    h = calc_hash(d, n)
    p = h
    if ht[p][0] == -1:
        ht[p][0] = d
        print("\nInserted data ,", d, " at position ", p, " successfully\n")
        return 0
    elif calc_hash(ht[p][0], n) == h:
        i = p
        for k in range(n):
            if ht[i][1] == -1:
                break
            i = ht[i][1]
        ni = i
        for k in range(n):
            ni += 1
            ni %= n
            if ht[ni][0] == -1:
                ht[ni][0] = d
                ht[i][1] = ni
                print("\nInserted data ,",d," at position ",ni," successfully\n")
                return 0
        print("\nNo empty space found \n")
        return 0
    else:
        k = ht[p][0]
        m = calc_hash(k,n)
        i = m

        for j in range(n):
            if ht[i][1] == p:
                break
            i = ht[i][1]

        ht[p][0] = d
        ht[p][1] = -1
        print("\nInserted data : ",d," at position ",p,"\n")
        l=p
        for j in range(n):
            l += 1
            l %= n
            if ht[l][0] == -1:
                ht[l][0] = k
                ht[i][1] = l
                return 0

    print("\nNo empty space found\n")


def search(d, ht):
    h = calc_hash(d, n)
    p = h
    noc = 0
    for j in range(n):
        if ht[p][0] == d:
            noc += 1
            print("\nElement found at , ", p,"Number of Comparisons : ",noc, "\n")
            return 0
        elif calc_hash(ht[p][0], n) == h:
            for i in range(n):
                p = ht[p][1]
                noc += 1
                if ht[p][0] == d:
                    noc+=1
                    print("\nFound at position ",p,"Number of Comparisons : ",noc,"\n")
                    return 0
            print("\nNot found \n")
            return 0
        else:
            noc += 1
            p += 1
            p %= n
    print("\nNot found\n")


def get_data():
    ch = 0
    while ch != 5:
        ch = int(input("1.Enter data\n2.Search\n3.Print Table\n4.Delete\n5.Exit"))
        if ch == 1:
            d = int(input("Enter data: "))
            insert(d, ht)
        elif ch == 2:
            d = int(input("Enter element to be searched: "))
            search(d, ht)
        elif ch == 3:
            count = 0
            print()
            for i in ht:
                if i[0] != -1:
                    print(count, ".", i[0], "Chain", i[1])
                count += 1
            print()
        elif ch == 4:
            i = int(input("Enter the element to be deleted : "))
            del_element(i,ht)
        else:
            pass


ht = []
n = 10
for i in range(n):
    row = [-1, -1]
    ht.append(row)
get_data()