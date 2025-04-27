"""..."""

print(
    "First"
    if (
        any(
            tuple(
                map(
                    lambda x: int(x) % 2 == 0,
                    input().split(),
                )
            )
        )
    )
    else "Second"
)
