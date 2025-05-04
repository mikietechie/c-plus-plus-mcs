import sys


def reverse_bytes(num):
    bytes_data = num.to_bytes(8, byteorder="little")
    reversed_bytes = bytes_data[::-1]
    return int.from_bytes(reversed_bytes, byteorder="little")


def main():
    zero = input()
    one = int(input())
    two = list(map(int, input().split()))

    if zero == "encode":
        n = one
        numbers = two
        print(n)
        print(" ".join(map(str, numbers)))
    else:
        k = one
        numbers = two
        for i in range(k):
            reversed_num = reverse_bytes(numbers[i])
            if reversed_num == numbers[i]:
                print(numbers[i], end=" ")
            else:
                print(reversed_num, end=" ")
        print()


if __name__ == "__main__":
    main()
