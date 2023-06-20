n, m = [int(x) for x in input().split(' ')]

resp = 2*(2**(n-1) + 2**(m-1) - 1)

print(resp)