def primes():
    number = 2
    while True:
        prime = True
        for i in range(2, number):
            if number % i == 0:
                prime = False
                break
        if prime:
            yield number
        number += 1
