# Online Python - IDE, Editor, Compiler, Interpreter
point2_x, point2_y = [float(i) for i in input().split()]
point1_x, point1_y = [float(l) for l in input().split()]
delta_y = point2_y - point1_y
delta_x = point2_x - point1_x
new_point1_x = point2_x - delta_y
new_point1_y = point2_y + delta_x
new_point2_x = point1_x - delta_y
new_point2_y = point1_y + delta_x

print(new_point2_x, new_point2_y)
print(new_point1_x, new_point1_y)


def sum(a, b):
    return a + b
