dict_size = int(input())
dictionary = set()
for i in range(0, dict_size):
    dictionary.add(input().lower())

unknown_words = set()
lines = int(input())
for i in range(0, lines):
    for word in input().split():
        s_word = word.lower()
        if s_word not in dictionary:
            unknown_words.add(s_word)

for word in unknown_words:
    print(word)
