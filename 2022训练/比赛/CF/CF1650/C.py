from filecmp import cmp


t = int(input())
def takeSecond(a):
    return a[1]
while(t):
    x = input()
    n,m = list(map(int,input().split()))
    a = []
    for i in range(m):
        x,y = list(map(int,input().split()))
        a.append([y,x,i])
    a.sort()
    b = []
    ans = 0
    a = a[:2 * n]
    a.sort(key=takeSecond)
    for i in range(n):
        ans += a[i][0] + a[2*n-i-1][0]
        b.append([a[i][2]+1,a[2*n-i-1][2]+1])
    print(ans)
    for x in b:
        print(x[0],x[1])
    t -= 1
