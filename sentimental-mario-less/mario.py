import cs50



while True:
    height = cs50.get_int("enter a height: ")
    if height > 0 and height < 9:
        break


dot = height
hash = 0

for n in range(height):
    dot -= 1
    n += 1
    for j in range(dot):
        print(".")
    for k in range(hash):
        print("#")
