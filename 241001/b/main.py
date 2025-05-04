"""..."""

from __future__ import annotations
from dataclasses import dataclass
import itertools


@dataclass
class Dwarf(object):
    """..."""

    name: int
    cuddle_time: int
    sleep_time: int

    wakes_after: int = 0
    sleeping: bool = False

    def clone(self) -> Dwarf:
        """..."""
        return Dwarf(
            cuddle_time=self.cuddle_time,
            sleep_time=self.sleep_time,
            name=self.name,
        )

    def reset(self):
        """..."""
        self.wakes_after = 0
        self.sleeping = False

    def __str__(self):
        """..."""
        return str(self.name)

    def __eq__(self, value: Dwarf):
        return self.name == value.name


@dataclass
class SleepingOrder(object):
    """..."""

    dwarfs: tuple[Dwarf]

    def feasible(self) -> bool:
        """..."""
        for dwarf in self.dwarfs:
            # 1 Cuddle dwarf for cuddle time minutes
            for otherdwarf in self.dwarfs:
                if otherdwarf == dwarf:
                    continue
                if otherdwarf.sleeping:
                    otherdwarf.wakes_after -= dwarf.cuddle_time
                    if otherdwarf.wakes_after < 1:
                        return False
            # send dwarf to sleep
            dwarf.wakes_after = dwarf.sleep_time
            dwarf.sleeping = True
        # print("*" * 20)
        # print(self)
        # for dwarf in self.dwarfs:
        #     print(repr(dwarf))

        return True

    def __str__(self):
        return " ".join([str(d) for d in self.dwarfs])


def main():
    """..."""
    n = int(input())
    a_array = list(map(int, input().split()))
    b_array = list(map(int, input().split()))
    dwarfs: list[Dwarf] = []
    for i in range(n):
        dwarf = Dwarf(
            cuddle_time=a_array[i],
            sleep_time=b_array[i],
            name=i + 1,
        )
        dwarf.reset()
        dwarfs.append(dwarf)
    permutations = itertools.permutations(dwarfs)
    for p in permutations:
        _dwarfs = [d.clone() for d in p]
        sleeping_order = SleepingOrder(dwarfs=_dwarfs)
        if sleeping_order.feasible():
            print(sleeping_order)
            return
    print(-1)


if __name__ == "__main__":
    main()
