a = 2
b = 16

for i in range(a, b + 1):
    print(str(i) + "|" + bin(i))
    print(str(a) + "|" + bin(a))
    print(bin(a ^ i))
    print(a ^ i)
    print()
    