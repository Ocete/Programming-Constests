# In the name of God
T = int(input())  # read a line with a single integer

for t in range(1, T+1):
    U = int(input())
    ocurrences = {}
    s = set()

    for i in range(10**4):
        num,str = input().split(' ')
        letter = str[0]

        if letter not in ocurrences.keys():
            ocurrences[ letter ] = 0

        ocurrences[ letter ] += 1
        if len(s) < 10:
            for c in str:
                s.add(c)


    ocurrences2 = sorted(ocurrences.items(), key=lambda x: -x[1])
    result = ''.join([elem[0] for elem in ocurrences2])

    for a in s:
        if a not in result:
            result = a+result

    print( "Case #{}: {}".format(t, result) )
