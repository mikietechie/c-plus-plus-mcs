"""...."""


def main():
    """...."""
    nums: set[int] = set()
    n = int(input())
    output: list[str] = []
    for _ in range(n):
        user_input = input()
        cmd = user_input[0]
        args = tuple(map(int, user_input[2:].split()))
        if cmd == "+":
            nums.add(args[0])
        else:
            l, r = args
            ans = 0
            for num in nums:
                if num >= l:
                    if num > r:
                        break
                    ans += num
            output.append(str(ans))
    print("\n".join(output))


if __name__ == "__main__":
    main()
