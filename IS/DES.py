from Crypto.Cipher import DES  #pip install pycryptodome
import math

def pad(text):
    n = 8 - (len(text) % 8)
    return text + (b' ' * n)

key = b'abcdefgh'
des = DES.new(key, DES.MODE_ECB)

text = input("Enter the message to be encrypted: ").encode()
padded_text = pad(text)

# Ensure the padded_text length is a multiple of 8
while len(padded_text) % 8 != 0:
    padded_text += b' '

encrypted_text = des.encrypt(padded_text)
print("Encrypted text:", encrypted_text)

decrypted_text = des.decrypt(encrypted_text)
print("Decrypted text:", decrypted_text.decode().rstrip())
