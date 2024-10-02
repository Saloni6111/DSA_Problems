"""
Problem Defination: Tower of Hanoi
---
The Tower of Hanoi is a classic recursive algorithm used to solve a mathematical puzzle. It involves three rods and a set of disks of different sizes. The objective is to move all the disks from one rod to another, following these rules: only one disk can be moved at a time, a larger disk cannot be placed on top of a smaller one, and all disks must be moved from the source rod to the destination rod using an auxiliary rod.

"""
def move(n: int, src: str, dest: str) -> None:
    """
    Function to demonstarte movement of a disk from source to destination.

    Args
    ----
    :param n: The number of the disk that have to move.
    :param src: String representation of the source rod.
    :param dest: String representation of the destination rod.
    """

    print(f"Moving disk {n} from source {src} to destination {dest}")



def tower_of_hanoi(n: int, src: str, dest: str, aux: str) -> None:
    """
    Function to move n disks from source to destination using auxilary.

    Args
    ----

    :param n: The number of disks that have to move.
    :param src: String representation of the source rod.
    :param dest: String representation of the destination rod.
    :param aux: String representation of the auxilary rod.
    """

    if n < 1: # The number of disks can not be less than 1
        return

    if n == 1: # base case
        move(n, src, dest)
        return

    tower_of_hanoi(n - 1, src, aux, dest) # move n - 1 disks from src to aux using dest as auxilary
    move(n, src, dest) # move the last disk from source to destination
    tower_of_hanoi(n - 1, aux, dest, src) # move n - 1 disks from aux to dest using src as auxilary


def main() -> None:
    n = 4 # number of disks in Tower of Hanoi

    source_rod = 'A' # String representation of the source rod.
    destination_rod = 'B' # String representation of the destination rod.
    auxilary_rod = 'C' # String representation of the auxilary rod.

    tower_of_hanoi(n, source_rod, destination_rod, auxilary_rod) # simple demonstration of Tower of Hanoi


if __name__ == "__main__":
    main()