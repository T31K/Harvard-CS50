from cs50 import get_float

while True:
    input = get_float("Change owed: ")
    if input > 0:
        break

coins = 0
input = input * 100

while input >= 25:
    input -= 25
    coins += 1

while input >= 10:
    input -= 10
    coins += 1

while input >= 5:
    input -= 5
    coins += 1

while input >= 1:
    input -= 1
    coins += 1

print(coins)

