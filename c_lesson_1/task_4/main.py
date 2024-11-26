"""
Input l, r, d
Print all numbers from l to r inclusive, that are divisible by d
"""


def function(l: int, r: int, d: int) -> str:
    """
    Prints all numbers divisible by D
    """
    output = ""
    counter = l
    while counter <= r:
        remainder = counter % d
        if remainder == 0:
            output = f"{output} {counter}"
        counter += 1
    return output.strip()


if __name__ == "__main__":
    print(function(3, 5, 2))
