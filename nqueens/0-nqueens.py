#!/usr/bin/python3
"""Solve the N Queens problem using backtracking."""

import sys


def is_safe(queens, row, column):
    """Check whether a queen can be placed at the given position."""
    for queen_row, queen_column in queens:
        if queen_column == column:
            return False

        if abs(queen_row - row) == abs(queen_column - column):
            return False

    return True


def solve_nqueens(size, row, queens):
    """Find and print every valid solution to the N Queens problem."""
    if row == size:
        print(queens)
        return

    for column in range(size):
        if is_safe(queens, row, column):
            queens.append([row, column])
            solve_nqueens(size, row + 1, queens)
            queens.pop()


def main():
    """Validate arguments and solve the N Queens problem."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        size = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if size < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(size, 0, [])


if __name__ == "__main__":
    main()
