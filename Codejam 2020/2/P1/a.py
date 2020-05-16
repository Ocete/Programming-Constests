# In the name of God
T = int(input())  # read a line with a single integer

for t in range(1, T+1):
    L, R = [int(s) for s in input().split(" ")]

    i = 1
    while i <= L or i <= R:
        if L >= R:
            L -= i
        else:
            R -= i
        i += 1
    i -= 1

    print( "Case #{}: {} {} {}".format(t, i, L, R) )
