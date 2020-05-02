# In the name of God
from collections import Counter
from copy import deepcopy
T = int(input())  # read a line with a single integer


def cut(pancakes, D, cortes):
    if (cortes > 50):
        return D-1
    c = Counter(pancakes)
    if (c.most_common(1)[0][1] >= D):
        return 0

    result = 50
    for p in pancakes:
        p2 = deepcopy(pancakes)
        p2.remove(p)
        p2.append(p/2)
        p2.append(p/2)
        result = min(result, 1 + cut(p2, D, cortes+1))

    max = c.most_common(1)[0][1]
    pancakes_filtered = [ x[0] for x in c.items() if (x[1] >= max) ]
    minn = min(pancakes_filtered)
    p = [x for x in pancakes if x > minn]
    greater_p = len(p)
    missing = D - max
    if (greater_p >= missing):
        result = min(result, missing)


    return result

for t in range(1, T+1):
    N, D = [int(x) for x in input().split(' ')]
    pancakes_line = [int(x) for x in input().split(' ')]
    result = cut(pancakes_line, D, 0)

    print( "Case #{}: {}".format(t, result) )
