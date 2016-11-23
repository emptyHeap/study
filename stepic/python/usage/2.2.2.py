import simplecrypt

passwords = []

with open("passwords.txt", "r") as passwords_file:
    passwords = passwords_file.readlines()

with open("encrypted.bin", "rb") as binfile:
    encrypted = binfile.read()

for password in passwords:
    try:
        decrypted = simplecrypt.decrypt(password.strip(),encrypted)
    except:
        print('bad password: ' + password)
    else:
        print('success with password: ' + password)
        print(decrypted)
        break
