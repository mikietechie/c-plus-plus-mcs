import os

dirs = [
    "250213",
    "250227",
    "250313",
    "250320",
]

cpp = """
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    return 0;
}

"""
cpp = """
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    return 0;
}

"""

py = """
def main():
    ""
    ans = None
    print(ans)

if __name__ == "__main__":
    main()

"""

for _dir in dirs:
    os.mkdir(_dir)
    for i in range(65, 65 + 20):
        task_path = f"{_dir}{os.sep}{chr(i)}".lower()
        os.mkdir(task_path)
        with open(
            f"{task_path}{os.sep}main.cpp",
            "w",
            encoding="UTF-8",
        ) as f:
            f.write(cpp)
        with open(
            f"{task_path}{os.sep}main.py",
            "w",
            encoding="UTF-8",
        ) as f:
            f.write(py)
