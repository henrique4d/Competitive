
n = int(input())

classes = 4

resp = 2*4*3*(4**(n-3))


resp += (n-3)*4*3*3* (4**(n-4))


print(int(resp))