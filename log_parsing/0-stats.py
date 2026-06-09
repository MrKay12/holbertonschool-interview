#!/usr/bin/python3
"""Log parsing script."""

import re
import sys


VALID_CODES = (200, 301, 400, 401, 403, 404, 405, 500)

PATTERN = re.compile(
    r'^\S+ - \[.*\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
)


def print_stats(total_size, status_counts):
    print("File size: {}".format(total_size))
    for code in VALID_CODES:
        if status_counts.get(code, 0) > 0:
            print("{}: {}".format(code, status_counts[code]))


def main():
    total_size = 0
    status_counts = {code: 0 for code in VALID_CODES}
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1
            line = line.strip()

            match = PATTERN.match(line)
            if match:
                status_code = int(match.group(1))
                file_size = int(match.group(2))

                total_size += file_size

                if status_code in status_counts:
                    status_counts[status_code] += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

        print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise


if __name__ == "__main__":
    main()