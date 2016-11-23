# put your python code here
arguments = []
matrix = []
result = []
sl = 0

arguments = input()

while arguments != "end" :
    matrix.append([ int(i) for i in arguments.split() ])
    arguments = input()


ml = len(matrix)
for num, el in enumerate(matrix) :
    result.append(matrix[(ml+num-1)%len(matrix)] + 
                  matrix[(ml+num+1)%len(matrix)] +
                  matrix[(ml+num-sl)%len(matrix)] +
                  matrix[(ml+num+sl)%len(matrix)])

print (result)
print (enumerate(result))
for num, el in enumerate(result) :
    print(el)
    if num%el == 0 :
        print("\n")
    else:
        print(" ")
