"""..."""

num = int(input())
print("First" if not (num % 8 == 0 or num % 8 == 1) else "Second")
