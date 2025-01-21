import math
n = int(input())
 
arr = input().split(' ')
arr2 = []
 
# print(n)
 
# print(arr)
 
resp = 0
aux = 1
 
for j in range(len(arr)):
    arr2.append (math.log2(int(arr[j])))
    # print(arr2[j])
    resp = max(resp, arr2[j])
    
arr = arr2
arr2 = []
arr.append(10000000000)
for i in range(3000):
    # print(arr)
    if len(arr) == 1:
        break
    
    for j in range(len(arr)-1):
        if int(arr[j]) == i and int(arr[j+1]) == i:
            arr2.append(i+1)
            # print("adicionando ")
            # print(i+1)
            # print(j)
            # print("aumentando o j")
            arr[j+1] = -1
            # print(j)
            
            resp = max(resp,i+1)
        elif arr[j] >= i:
            arr2.append(arr[j])

    if arr[len(arr)-1] >= i:
        arr2.append(arr[len(arr)-1])
    
    arr = arr2
    # print(arr)

    arr2 = []
 
resp = int(2**resp)
print(resp)