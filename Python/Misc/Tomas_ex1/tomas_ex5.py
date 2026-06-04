# 42 Caesar Cipher

# Basis strings (Constants)
BASIS_UPPERCASE = "QICKNYMPHBUGSVEXFJORDWALTZ"
BASIS_LOWERCASE = "qicknymphbugsvexfjordwaltz"


# Define functions
# Create menu
def create_menu():
    print("==== Modified 42 Caesar Cipher ====")
    print("[1] Cipher a String")
    print("[2] Decipher a String")
    print("[3] Add a line in the Queue")
    print("[4] Edit a line in the Queue")
    print("[5] Delete a line in the Queue")
    print("[6] Cipher the Queue")
    print("[7] Decipher the Queue")
    print("[8] Clear the Queue")
    print("[9] View Queue")
    print("[0] Exit")
    return int(input("Enter a choice: "))


# ------ Encipher ---
def choose_basis(char):
    # Determine which basis to use
    # - Uppercase letters USE uppercase basis
    # - Lowercase letters USE lowercase basis
    if char.isupper():
        return BASIS_UPPERCASE
    else:
        return BASIS_LOWERCASE
def encipher_char(basis, origin_index, basis_index):
    # Even-index: shift 4-position right (ref: basis)
    # Odd-index : shift 2-position left (ref: basis)
    if  origin_index % 2 == 0:
        return (basis_index + 4) % len(basis)
    else:
        return (basis_index - 2) % len(basis)
def  mod42_caesar_cipher(input):
    # Find characters at odd and even indices
    cipher_text = ""
    for char in input:

        origin_index = input.index(char)

        # Ignore non-alphabetic characters
        if not char.isalpha():
            cipher_text += char
            continue

        # Which basis to use?
        basis = choose_basis(char)

        # Take index of the letter in the basis
        basis_index = basis.index(char)

        # Use modified 42 Caesar cipher
        basis_index = encipher_char(basis, origin_index, basis_index)

        # Append to final text
        cipher_text += basis[basis_index]

    return cipher_text


# ------ Decipher ---
def decipher_char(basis, origin_index, basis_index):
    # Even-index: shift 4-position left (ref: basis)
    # Odd-index : shift 2-position right (ref: basis)
    if origin_index % 2 == 0:
        return (basis_index - 4) % len(basis)
    else:
        return (basis_index + 2) % len(basis)
def mod42_caesar_decipher(input):
     # Find characters at odd and even indices
     decipher_text = ""
     for char in input:

         origin_index = input.index(char)

         # Ignore non-alphabetic characters
         if not char.isalpha():
             decipher_text += char
             continue

         # Which basis to use?
         basis = choose_basis(char)

         # Take index of the letter in the basis
         basis_index = basis.index(char)

         # Decipher modified 42 Caesar ciphertext
         basis_index = decipher_char(basis, origin_index, basis_index)

         # Append to final text
         decipher_text += basis[basis_index]

     return decipher_text


# ------ Add Line ---
def add_line(queue):
    # Prompt user
    word = input("Enter the string: ")

    # Add word to queue
    queue.append(word)

    # Success message
    print("Line added")


# ------ Edit Line ---
def edit_line(queue):
    # Print queue
    view_queue(queue)

    # Prompt user
    edit_line = int(input("Enter the index of the line to be edited: "))
    updated_value = input("Enter the updated string: ")
    queue[edit_line] = updated_value
    print("Line successfully edited.")


# ------ Delete Line ---
def delete_line(queue):
    # Print queue
    view_queue(queue)

    # Promp User
    delete_line = int(input("Enter the index of the line to be deleted: "))

    # Delete item
    del queue[delete_line]


# ------ Cipher Queue ---
def cipher_queue(queue):
    ciphered_queue = []
    for item in queue:
        ciphered_queue.append(mod42_caesar_cipher(item))

    # Print ciphered items
    view_queue(ciphered_queue)


def decipher_queue(queue):
    deciphered_queue = []
    for item in queue:
        deciphered_queue.append(mod42_caesar_decipher(item))

    # Print deciphered items
    view_queue(deciphered_queue)


def clear_queue(queue):
    queue.clear()
    print("Queue cleared.")


def view_queue(queue):
    print("Queue:")
    for i in range(len(queue)):
        print(f"[{i}] " + queue[i])


# ------ Main ------
# Init queue
queue = []
while True:
    # Prompt user
    choice = create_menu()
    print()
    match choice:
        case 1:
            word = input("Enter the string: ")
            cipher_text = mod42_caesar_cipher(word)
            print("Result: " + cipher_text)

        case 2:
            word = input("Enter the string: ")
            decipher_text = mod42_caesar_decipher(word)
            print("Result: " + decipher_text)

        case 3:
            add_line(queue)

        case 4:
            edit_line(queue)

        case 5:
            delete_line(queue)

        case 6:
            cipher_queue(queue)

        case 7:
            decipher_queue(queue)

        case 8:
            clear_queue(queue)
    
        case 9:
            view_queue(queue)

        case 0:
            break