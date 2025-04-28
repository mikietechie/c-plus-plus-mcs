"""......."""


def main():
    """......."""
    total, operations = map(int, input().split())

    # Create an initial sequence of soldiers '1', '2', ..., 'n'
    soldiers = "".join(str(i) for i in range(1, total + 1))

    for _ in range(operations):
        start, end = map(int, input().split())
        start -= 1  # Adjust to 0-based index
        end -= 1

        # Extract the segment, remove it, and move it to the front
        segment = soldiers[start: end + 1]
        soldiers = soldiers[:start] + soldiers[end + 1:]
        soldiers = segment + soldiers

    # Output the final sequence
    print(" ".join(soldiers))


if __name__ == "__main__":
    main()
