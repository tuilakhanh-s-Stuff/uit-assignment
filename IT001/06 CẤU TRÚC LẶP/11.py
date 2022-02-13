print("n:")
n = int(input())
if (2 <= n  and n <= 10**9) is False:
    print("Sai giá trị")
    exit()

print("k:")
k = int(input())
if (2 <= k  and k <= n) is False:
    print("Sai giá trị")
    exit()

print("p:")
p = int(input())
if (1 <= p  and p <= (n+1)/2) is False:
    print("Sai giá trị")
    exit()

print("q:")
q = int(input())
if (1 <= q  and q <= 2) is False:
    print("Sai giá trị")
    exit()

lapde = n/k
if isinstance(n/k, int) is False:
    lapde = int(lapde)+1

de = []
for i in range(lapde):
    sode = len(de)
    for z in range(k):
        de.append(z)
        if len(de) == n: break

vitria = p*q
for i in range(vitria-1, 1, -1):
    if de[i] == de[vitria]:
        u = round(i/2)
        if (i % 2) == 0:
            v = 2
        else:
            v = 1
        print(u, v)
        exit()

for i in range(vitria+1, n):
    if de[i] == de[vitria]:
        u = round(i/2)
        if (i % 2) == 0:
            v = 2
        else:
            v = 1
        print(u, v)
        exit()

print(-1, -1)