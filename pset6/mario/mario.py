from cs50 import get_int

while True:
    input = get_int("Insert number: ")
    input = int(input)
    if input in range(1, 9):
        break

spaces = input - 1
hash = 1

for i in range(input):
    print((" " * spaces) + ("#" * hash))
    spaces -= 1
    hash += 1

