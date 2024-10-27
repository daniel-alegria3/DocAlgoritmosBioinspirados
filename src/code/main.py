from time import time_ns

try:
    t1 = time_ns()

    binary1 = input("Enter binary1: ")
    decimal1 = int(binary1, 2)

    binary2 = input("Enter binary2: ")
    decimal2 = int(binary2, 2)

except ValueError:
    print("Error: Input is not Binary Number.")

else:
    t2 = time_ns()
    te = (t2-t1)*(10**6)

    rpta = decimal1 * decimal2
    print(f"{decimal1} * {decimal2} = {rpta}, {te} ms")

