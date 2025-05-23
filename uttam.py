t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    count_a = 0
    count_d = 0
    for j in range(n):
        if arr[j] != j + 1:
            count_a += 1
        if arr[j] != n - j:
            count_d += 1
    if count_a <= count_d:
        print("Win")
    else:
        print("Tie")