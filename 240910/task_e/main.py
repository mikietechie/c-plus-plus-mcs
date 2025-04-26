"""
Find the most common letter
"""


def function(word: str) -> str:
    """
    Find the most common letter
    """
    word_length = len(word)
    outer_index = 0
    most_common_char = ""
    most_common_count = 0
    current_char = ""
    if word_length > 0:
        most_common_char = word[0]
        # current_char = word
    while outer_index < word_length:
        current_char = word[outer_index]
        current_count = 0
        inner_index = 0
        while inner_index < word_length:
            char_at_index = word[inner_index]
            if char_at_index == current_char:
                current_count += 1
            inner_index += 1
        if current_count > most_common_count:
            most_common_count = current_count
            most_common_char = current_char
        outer_index += 1
    return most_common_char


if __name__ == "__main__":
    print(function("baacb"))
