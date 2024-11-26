"""
Задача C. Позиционные системы счисления
Имя входного файла: стандартный ввод
Имя выходного файла: стандартный вывод
Ограничение по времени: 2 секунды
Ограничение по памяти: 256 мебибайт
Задано число n в пятеричной записи. Вычислите сумму цифр в семеричной записи
этого числа
и выведите эту сумму как троичное число.
Формат входных данных
В единственной строке задано целое число n в пятеричной записи без ведущих
 нулей
(1 6 n 6 109
).
Формат выходных данных
Выведите одно число — сумму цифр в семеричной записи числа n, представленную
 в троичной
записи без ведущих нулей.
Примеры
стандартный ввод стандартный вывод
1 1
123 22
Пояснения к примерам
В первом примере 15 = 17, сумма цифр равна 13.
Во втором примере 1235 = 1 · 25 + 2 · 5 + 3 · 1 = 25 + 10 + 3 = 38,
 в семеричной записи
38 = 5 · 7 + 3 · 1 = 537, сумма цифр равна 8 = 2 · 3 + 2 · 1 = 223.
"""


def convert_base_n_to_base_10(number: str, base_n: int) -> str:
    """
    Convert a number to base 10
    """
    base_10_number = 0
    length = len(number)
    counter = length-1
    while counter >= 0:
        digit = number[counter]
        value = base_n**(length-(counter+1))
        char_value = int(digit)
        base_10_number += value*char_value
        counter -= 1
    return str(base_10_number)


def convert_base_10_to_base_n(number: str, base_n: int) -> str:
    """
    Convert a number in base 10 to base n
    """
    base_n_number = ""
    numerator = int(number)
    while numerator != 0:
        remainder = numerator % base_n
        numerator = numerator // base_n
        base_n_number = f"{remainder}{base_n_number}"
    return base_n_number


def convert_from_base_5_to_base_7(n: str) -> str:
    """
    Convert n from base 5 to base 7
    """
    base_10 = convert_base_n_to_base_10(n, 5)
    base_7 = convert_base_10_to_base_n(base_10, 7)
    return base_7


if __name__ == "__main__":
    print(convert_base_10_to_base_n("123", 5))
