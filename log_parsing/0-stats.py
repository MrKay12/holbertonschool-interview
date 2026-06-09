#!/usr/bin/python3
"""Log parsing module."""

import sys


def print_stats(total_size, status_codes):
    """Print total file size and status code counts."""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """Read stdin line by line and compute metrics."""
    total_size = 0
    line_count = 0
    valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]
    status_codes = {code: 0 for code in valid_codes}

    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.split()

            try:
                status_code = int(parts[-2])
                file_size = int(parts[-1])
            except (IndexError, ValueError):
                continue

            total_size += file_size

            if status_code in status_codes:
                status_codes[status_code] += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

        print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise


if __name__ == "__main__":
    main()