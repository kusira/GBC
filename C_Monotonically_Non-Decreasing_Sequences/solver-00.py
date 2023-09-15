MOD = 998244353

n = int(input())
A = [*sorted(map(int, input().split()))]

con = 1
ans = 1

for p, a in zip(A, A[1:]):
    if p == a:
        con += 1
    else:
        con = 1
    ans *= con
    ans %= MOD

print(ans)
