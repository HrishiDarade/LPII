from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

def pad(text):
    # Add padding to make the input text length a multiple of 16 bytes
    padding_length = AES.block_size - (len(text) % AES.block_size)
    padding = chr(padding_length).encode() * padding_length
    return text + padding

def unpad(padded_text):
    # Remove padding from the decrypted text
    padding_length = padded_text[-1]
    return padded_text[:-padding_length]

def encrypt(key, text):
    # Generate a random initialization vector (IV)
    iv = get_random_bytes(AES.block_size)
    
    # Create the AES cipher object
    cipher = AES.new(key, AES.MODE_CBC, iv)
    
    # Add padding to the text
    padded_text = pad(text)
    
    # Encrypt the padded text
    encrypted_text = cipher.encrypt(padded_text)
    
    # Return the IV and encrypted text as bytes
    return iv + encrypted_text

def decrypt(key, encrypted_text):
    # Extract the IV from the encrypted text
    iv = encrypted_text[:AES.block_size]
    
    # Create the AES cipher object
    cipher = AES.new(key, AES.MODE_CBC, iv)
    
    # Decrypt the encrypted text
    decrypted_text = cipher.decrypt(encrypted_text[AES.block_size:])
    
    # Remove padding from the decrypted text
    unpadded_text = unpad(decrypted_text)
    
    # Return the decrypted text as a string
    return unpadded_text.decode()

# Main program
key = input("Enter the AES key (16, 24, or 32 bytes): ").encode('utf-8')#put any key of 16, 24, 32 byte long, for ex: 0123456789ABCDEF 
text = input("Enter the message to be encrypted: ").encode('utf-8')

encrypted_text = encrypt(key, text)
print("Encrypted text:", encrypted_text)

decrypted_text = decrypt(key, encrypted_text)
print("Decrypted text:", decrypted_text)
