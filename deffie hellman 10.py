def power(base, exp, mod):
    res = 1
    base %= mod
    while exp > 0:
        if exp % 2 == 1:
            res = (res * base) % mod
        base = (base * base) % mod
        exp //= 2
    return res

def diffie_hellman():
    p = 23
    g = 5
    a = 6
    b = 15

    A = power(g, a, p)
    B = power(g, b, p)

    secret_alice = power(B, a, p)
    secret_bob = power(A, b, p)

    print(f"Alice's secret: {secret_alice}")
    print(f"Bob's secret: {secret_bob}")

if __name__ == "__main__":

    diffie_hellman()
