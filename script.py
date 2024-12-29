import os


code = (
    """
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    return 0;
}
"""
)

for i in range(2, 15):
    for j in range(97, 112):
        dir_path = f"lesson_{i}/{chr(j)}"
        os.mkdir(dir_path)
        with open(f"{dir_path}/main.cpp", "w", encoding="UTF-8") as f:
            f.write(code)
