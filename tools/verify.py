#!/usr/bin/env python3
"""Verify the exact preservation image used by this project."""

from hashlib import sha1
from pathlib import Path
import sys

EXPECTED_SIZE = 0x2000000
EXPECTED_SHA1 = "711c79790a713e65cc2ecb4857f35898b8e92985"


def main() -> int:
    if len(sys.argv) != 2:
        print(f"usage: {Path(sys.argv[0]).name} ROM", file=sys.stderr)
        return 2
    path = Path(sys.argv[1])
    data = path.read_bytes()
    digest = sha1(data).hexdigest()
    valid = len(data) == EXPECTED_SIZE and digest == EXPECTED_SHA1
    print(f"size: {len(data)}")
    print(f"sha1: {digest}")
    print("status: exact" if valid else "status: mismatch")
    return 0 if valid else 1


if __name__ == "__main__":
    raise SystemExit(main())
