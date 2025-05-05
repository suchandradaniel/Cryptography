def feistel(right, key):
    return right ^ key  # Simple XOR-based function

def toy_des_encrypt(plaintext, key):
    left = (plaintext & 0xF0) >> 4
    right = plaintext & 0x0F

    f = feistel(right, key)
    new_right = left ^ f

    ciphertext = (right << 4) | new_right
    return ciphertext

# Example usage
plaintext = 0xAB  # 10101011
key = 0x0D        # 00001101

encrypted = toy_des_encrypt(plaintext, key)
print(f"Encrypted: 0x{encrypted:02X}")
