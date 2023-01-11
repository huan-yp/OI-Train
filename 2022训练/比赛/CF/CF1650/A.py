t = int(input())
while(t):
    flag = 0
    str = input()
    ch = input()
    n = len(str)
    for i,x in enumerate(str):
        if(i % 2 == 0 and (n - i) % 2 == 1 and x == ch):
            flag = 1
    if(flag):
        print("YES")
    else:
        print("NO")
    t -= 1
