

def dfs(pos, val, resp):
    if pos == -1:
        resp = min(resp, val)
        return resp

    if s[pos] == 'O':
        if (val-1)%3 == 0 and ((val-1)/3)%2 == 1:
            if (val-1)/3 <= 1:
                return 10000000000000000000
            return dfs(pos-1, (val-1)/3, resp)

    elif s[pos] == 'E':
        if int((val*2)).bit_count() == 1:
            return 10000000000000000000
        return dfs(pos-1, val*2, resp)

    return 10000000000000000000

s = input()

for i in range(len(s)-1):
    if s[i] == 'O' and s[i+1] == 'O':
        print("INVALID")
        exit(0)

if s[len(s)-1] != 'O':
    print("INVALID")
    exit(0)

aux = 1
resp = 10000000000000000000

for i in range(300):
    resp = min(resp,dfs(len(s)-1, aux, resp))
    aux*=2

if resp < 10000000000000000000:
    print(int(resp))
else:
    print("INVALID")