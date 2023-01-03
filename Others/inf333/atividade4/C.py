v = [0]*301
fat = 1

for i in range(1,301):
    fat*=i
    v[i] = fat

val = 0
while(True):
    val = int(input())
    if (val == 0):
        break
    resp = 1
    for i in range(val+2, 2*val+1):
        resp*=i
    print(resp)