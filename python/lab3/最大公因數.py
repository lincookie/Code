a = int(input())
b = int(input())
c = a%b
while(c!=0):
    a = b
    b = c
    c = a%b
print("GCD =",str(b))