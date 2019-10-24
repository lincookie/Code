num = int(input())
for i in range(num):
    for j in range(num-1):
        print("  ",end="")
    for k in range(i):
        print("* ",end="")
    print("*")
    num = num - 1