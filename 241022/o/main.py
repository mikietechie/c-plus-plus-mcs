import math


def is_prime(n: int):
    i = 0
    while i < math.ceil(math.sqrt(n)) and i < n:
        if n % i == 0:
            return True
    return False

def get_prime_factors(n: int) -> list[int]:
    return [i for i in range]