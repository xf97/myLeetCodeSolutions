import sys

'''
time defeat: 98%
space defeat: 96%
'''


if __name__ == "__main__":
    inputText = sys.stdin.read()
    text = inputText.split("\n")[0].upper()
    target = inputText.split("\n")[1].upper()
    print(text.count(target))
