# put your python code here
arguments = []
matrix = []
result = []
sl = 0

arguments = input()

while arguments != "end" :
    matrix.append([ int(i) for i in arguments.split() ])
    arguments = input()


height = len(matrix)
line = 0
while line < height:
    width = len(matrix[line])
    element = 0
    row = []
    while element < width:
        row.append(
                matrix[line][(width + element - 1)%width] +
                matrix[line][(width + element + 1)%width] +
                matrix[(height + line + 1)%height][element] +
                matrix[(height + line - 1)%height][element])
        element += 1
    result.append(row)
    line += 1

for row in result:
    for element in row:
        print(str(element) + " ", end='')
    print()
