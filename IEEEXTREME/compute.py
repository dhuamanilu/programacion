def compute_output(A, B, C):
    # The Smali code for the computation goes here
    v0 = A
    v1 = B
    v2 = C
    v3 = 1
    v4 = v3 - v3
    v5 = v4 - v3
    v6 = v3
    v7 = v4
    v7 = v7 - v1
    v8 = v0
    v9 = v0
    v9 = v0 + v1
    v10 = v4
    v11 = v4
    v12 = v3

    while True:
        v11 = v11 + v1
        v10 = v10 + v0
        v13 = v10
        v14 = v4
        v15 = v4

        while True:
            v16 = v13 + v13
            if v16 <= v1:
                break
            v13 = v13 - v1
            v14 = v14 + v3
            v15 = v15 + v1

        if v13 > v4:
            v13 = v4 - v13

        v17 = v4
        v18 = v3

        while True:
            v17 = v17 + v13
            v18 = v18 + v3

            if v18 <= v6:
                continue

            break

        while True:
            v17 = v17 - v9
            v18 = v18 + v3

            if v18 <= v12:
                continue

            if v17 >= v4:
                break

            v5 = v14
            v6 = v12
            v7 = v15
            v8 = v10
            v9 = v13

        v12 = v12 + v3

        if v12 <= v2:
            continue

        return v6

# Read the number of test cases (T)
T = int(input())

for _ in range(T):
    A, B, C = map(int, input().split())
    result = compute_output(A, B, C)
    print(result)
