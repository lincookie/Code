a = int(input())
b = int(input())
ans = 0
for i in range(int(a/b)):
    ans += b * (i+1)
print ("sum =",'%d'%ans)