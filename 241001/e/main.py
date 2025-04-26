import statistics

int(input())
nums = list(map(int, input().split()))
print(statistics.median(nums))
