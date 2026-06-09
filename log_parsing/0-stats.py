#!/usr/bin/python3
"""Log parsing script."""

import sys


VALID_CODES = (200, 301, 400, 401, 403, 404, 405, 500)


def print_stats(total_size, status_counts):
    """Print accumulated metrics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_counts):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def parse_line(line):
    """Return status code and file size if line format is valid, else None."""
    parts = line.split()

    if len(parts) < 9:
        return None

    if parts[-5] != '"GET' or parts[-4] != "/projects/260" or parts[-3] != 'HTTP/1.1"':
        return None

    try:
        status_code = int(parts[-2])
        file_size = int(parts[-1])
    except ValueError:
        return None

    return status_code, file_size


def main():
    """Read stdin and print stats every 10 valid lines or on CTRL+C."""
    total_size = 0
    status_counts = {code: 0 for code in VALID_CODES}
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1

            parsed = parse_line(line)
            if parsed is not None:
                status_code, file_size = parsed
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