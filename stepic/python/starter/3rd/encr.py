letters = input()
code = input()

encript = {}
for i, letter in enumerate(letters):
    if letter in encript:
        continue
    else:
        encript[letter] = code[i]

decript = {}
for key, value in encript.items():
    decript[value] = key

print (''.join([encript[letter] for letter in input()]))
print (''.join([decript[letter] for letter in input()]))
