import sys
import pytest


def test_input():
    with open("data/test_input.in") as fh:
        sys.stdin = fh
        n = int(sys.stdin.readline())
        assert n == 3
        nums = [int(s) for s in sys.stdin.readline().split(" ")]
        assert nums == [1, 2, 3]