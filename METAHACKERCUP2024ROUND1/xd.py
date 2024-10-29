def sieve_of_eratosthenes(limit):
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False  # 0 y 1 no son primos
    for num in range(2, int(limit**0.5) + 1):
        if sieve[num]:
            for multiple in range(num*num, limit + 1, num):
                sieve[multiple] = False
    primes = [i for i, is_prime in enumerate(sieve) if is_prime]
    return primes, sieve

def count_subtractorizations(N, primes, is_prime):
    count = 0
    setXD = set()
    for b in primes:
        if b > N:
            break
        for c in primes:
            if c > b:
                break
            a = b - c
            if a > 0 and is_prime[a]:
                setXD.add((a))
    print("elements of setXD")
    for i in sorted(setXD):
        print(i)
    print("-----------------")
    return len(setXD)

# Fijamos el límite máximo hasta el cual necesitamos contar primos
MAX_N = 10000

# Precomputar los primos hasta el máximo valor N
primes, is_prime = sieve_of_eratosthenes(MAX_N)

# Calcular y mostrar los resultados para N desde 1 hasta 100
for N in range(10000, 10001):
    result = count_subtractorizations(N, primes, is_prime)
    print(f"Case #{N}: {result}")
