"""
Removes char in next string
"""


def function(s: str, t: str) -> str:
    """
    Remove every char in t from s
    """
    output = ""
    s_length = len(s)
    t_length = len(t)
    outer_index = 0
    while outer_index < s_length:
        s_char = s[outer_index]
        inner_index = 0
        in_t = False
        while inner_index < t_length:
            t_char = t[inner_index]
            if t_char == s_char:
                in_t = True
                break
            inner_index += 1
        if not in_t:
            output = f"{output}{s_char}"
        outer_index += 1
    return output


if __name__ == "__main__":
    print(function("cabbage", "face"))
