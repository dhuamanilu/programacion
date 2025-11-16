from math import *

n = int(input())
a = [int(i) for i in input().split()]
a = sorted(a)
if a[0]!=1:
    print(str(a[n-1]) + " 1")
elif n==1:
    print("*")
elif n==2:
    raiz = int(sqrt(a[1]))
    #print("esta es mi raiz" + str(raiz) + " " + str(a[1]))
    if (raiz*raiz)==a[1]:
        print(str(a[1])+" "+str(raiz))
    else:
        val = a[1] * a[1]
        print(str(val) +" "+str(val))
else:
    #supongamos que X es a[n - 1]
    S={1, 1, 1, 1}
    allPaired = True
    re1 = -1

    for i in range(0, n):
        S.add(a[i])

    for i in range(0,n):
        other = a[n - 1] // a[i]
        if other in S:
            continue
        else:
            allPaired = False
            re1 = other
    
    if not allPaired:
        print(str(a[n - 1]) +" "+str(re1))
    else:
        print(str(a[1] * a[n - 1]) +" "+str(a[1] * a[n - 1]))
