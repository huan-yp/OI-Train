t = int(input())
while(t):
    l,r,a = list(map(int,input().split()))
    if(a == 1):
        print(r)
        t -= 1
        continue
    if(l // a == r // a):
        print(r // a + r % a)
    else:
        print(r // a - 1 + a - 1 + (r % a == a - 1))
    t -= 1
