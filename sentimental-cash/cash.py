import cs50


def main():
    cents = get_cents()

    quarters = calculate_quarters(cents)
    cents = cents - quarters * 0.25

    dimes = calculate_dimes(cents)
    cents = cents - dimes * 0.10

    nickels = calculate_nickels(cents)
    cents = cents - nickels * 0.5

    pennies = calculate_pennies(cents)
    cents = cents - pennies * 0.1

    coins = quarters + dimes + cents + pennies

    print(f"{coins}")







def get_cents():
    while True:
        c = cs50.get_float("cents: ")
        if c > 0:
            break
    return c





def calculate_quarters(cents):
    x = cents
    qua = 0
    while True:
        x = x - 0.25
        if x < 0:
            break
        qua += 1
    return qua



def calculate_dimes(cents):
    y = cents
    dim = 0
    while True:
        y = y - 0.10
        if y < 0:
            break
        dim += 1
    return dim






def calculate_nickels(cents):
    z = cents
    nic = 0
    while True:
        z = z - 0.05
        if z <  0:
            break
        nic += 1
    return nic







def calculate_pennies(cents):
    e = cents
    pen = 0
    while True:
        e = e - 0.01
        if e < 0:
            break
        pen += 1
    return pen








main()
