#!/usr/bin/python
import sys

#71%, 88%
if __name__ == "__main__":
    inputNumsList = sys.stdin.readlines()
    for num in inputNumsList:
        print(int(num, 16))
