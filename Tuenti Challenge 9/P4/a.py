import numpy as np
from functools import reduce
from fractions import Fraction as frac

def Hack(M):
    dict = {}
    # Build de dict
    for i in range( len(M) ):
        if (M[i] not in dict):
            dict[M[i]] = 0
        dict[M[i]] = dict[M[i]]+1

    # Calculamos X
    m = []
    for a,b in dict.items():
        m.append( np.lcm(int(a),b)/b )

    m = list(map(lambda x: int(x), m))
    X = reduce(lambda x,y: np.lcm(x,y), m )

    # Caramelos por persona
    caram_pers = []
    for a,b in dict.items():
        caram_pers.append( b*X )
    sum = reduce((lambda x, y: x + y), caram_pers)

    # Contamos las personas
    pers = []
    for a,b in dict.items():
        pers.append( int(b*X/int(a)) )
    n_per = reduce((lambda x, y: x + y), pers)

    f = frac(sum, n_per)
    str = '{0}'.format(f)
    if ( str.find('/') == -1 ):
        str = str + '/1'
    return str

T = int(input())
for j in range(1,T+1):
    N = int(input())
    M = input().split()
    f = Hack(M)
    print( 'Case #{0}: {1}'.format(j,f) )
