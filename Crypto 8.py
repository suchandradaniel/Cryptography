def toy_des(x, k):
    left = (x >> 4) & 0xF
    right = x & 0xF
    return ((right << 4) | (left ^ (right ^ k)))

def triple_des_encrypt(p, k1, k2, k3):
    return toy_des(toy_des(toy_des(p, k1), k2), k3)

def triple_des_decrypt(c, k1, k2, k3):
    return toy_des(toy_des(toy_des(c, k3), k2), k1)

# Example
p = 0xAB
e = triple_des_encrypt(p, 0x1, 0x2, 0x3)
d = triple_des_decrypt(e, 0x1, 0x2, 0x3)

print(f"Encrypted: 0x{e:02X}")
print(f"Decrypted: 0x{d:02X}")
