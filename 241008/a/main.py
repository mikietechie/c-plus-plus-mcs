"""...."""

# import math

a, b = list(map(int, input().split()))
if b == 0:
    print("Na nol' delit' nel'zya!!!")
elif a == 0:
    print(0)
elif a > 0 and b > 0:
    print(a // b)
elif a < 0 and b < 0:
    print(abs(a) // abs(b))
else:
    print(-(abs(a) // abs(b)))
