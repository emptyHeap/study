base = input()
temp = input()
repl = input()
history = [base]

def check(string):
    global temp, repl, history

    res = string.replace(temp, repl)

    if temp not in string:
        print(len(history) - 1)
    elif (string in res) or (res in history) or (temp in repl):
        print("Impossible")
    else:
        history.append(res)
        check(res)

check(base)
