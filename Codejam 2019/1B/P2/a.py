import numpy as np

sist = np.array([[2,1,1,1,1,1], [4,2,1,1,1,1], [8,2,2,1,1,1],
[16,4,2,2,1,1], [32,4,2,2,2,1], [64,8,4,2,2,2]])

def intear(x):
    return int(x)

T = int(input())
for j in range(T):

    val = [315,252,,0,0,0]
    sol = [0,0,0,0,0,0]
    for i in range(6):
        print( i+1 )
        val[i] = int(input())

    sol = np.linalg.solve(sist, val)

    print ( val )
    for i in range(6):
        print( int(val[i]) , end=" ")
    # Print newline
    print()

    trash = int(input())

exit
