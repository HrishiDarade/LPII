def encrypt(message, key):
    # Calculate the number of rows needed based on the key length
    num_rows = len(message) // key
    if len(message) % key != 0:
        num_rows += 1

    # Create an empty grid with the calculated number of rows and the key as columns
    grid = [['' for _ in range(key)] for _ in range(num_rows)]

    # Fill the grid with the message
    index = 0
    for row in range(num_rows):
        for col in range(key):
            if index < len(message):
                grid[row][col] = message[index]
                index += 1
            else:
                break

    # Read the message column-wise to obtain the encrypted message
    encrypted_message = ''
    for col in range(key):
        for row in range(num_rows):
            encrypted_message += grid[row][col]

    return encrypted_message


def decrypt(encrypted_message, key):
    # Calculate the number of rows needed based on the key length
    num_rows = len(encrypted_message) // key

    # Create an empty grid with the calculated number of rows and the key as columns
    grid = [['' for _ in range(key)] for _ in range(num_rows)]

    # Fill the grid with the encrypted message column-wise
    index = 0
    for col in range(key):
        for row in range(num_rows):
            grid[row][col] = encrypted_message[index]
            index += 1

    # Read the grid row-wise to obtain the decrypted message
    decrypted_message = ''
    for row in range(num_rows):
        for col in range(key):
            decrypted_message += grid[row][col]

    return decrypted_message


# Example usage
message = input("Enter message: ")
key = int(input("Enter key: "))

encrypted_message = encrypt(message, key)
print("Encrypted message:", encrypted_message)

decrypted_message = decrypt(encrypted_message, key)
print("Decrypted message:", decrypted_message)
