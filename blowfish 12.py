from Crypto.Cipher import Blowfish
from Crypto.Util.Padding import pad, unpad

def encrypt(plaintext, key):
    cipher = Blowfish.new(key, Blowfish.MODE_ECB)
    padded_text = pad(plaintext.encode('utf-8'), Blowfish.block_size)
    return cipher.encrypt(padded_text)

def decrypt(ciphertext, key):
    cipher = Blowfish.new(key, Blowfish.MODE_ECB)
    padded_text = cipher.decrypt(ciphertext)
    return unpad(padded_text, Blowfish.block_size).decode('utf-8')

if __name__ == "__main__":
    key = b'abcdefgh'  # Must be between 4 and 56 bytes
    plaintext = "secret"
    ciphertext = encrypt(plaintext, key)
    decrypted_text = decrypt(ciphertext, key)

    print(f"Ciphertext: {ciphertext.hex()}")
    print(f"Decrypted: {decrypted_text}")
