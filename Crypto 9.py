p, q = 3, 11
n = p * q             # 33
phi = (p-1)*(q-1)     # 20
e = 3
d = 7                 # Since (e*d) % phi = 1

# Message
msg = 7

# Encrypt
cipher = pow(msg, e, n)
print("Encrypted:", cipher)

# Decrypt
plain = pow(cipher, d, n)
print("Decrypted:", plain)
