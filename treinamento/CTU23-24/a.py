
n = input()

s = input()

news = ""

last = '-'
for c in s:
    if last == '-':
        last = c
        news += c
        continue
    if last == ')' and c == '(':
        news += "*"
    if last == '(' and c == ')':
        news += "1"
    if last == ')' and c == ')':
        news += "+1"

    news += c   
    last = c

print(eval(news))