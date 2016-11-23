# put your python code here
size = int(input())
matrix = [[0 for i in range(size)] for j in range(size)]
full_length = size*size

class direction():
    right =     {'x' : 1, 'y' : 0}
    down =      {'x' : 0, 'y' : 1}
    left =      {'x' : -1, 'y' : 0}
    up =        {'x' : 0, 'y' : -1}

directions_sequence = [
        direction.right,
        direction.down,
        direction.left,
        direction.up
]

coords = {'x': -1, 'y': 0}
current_direction = 0 
length = size
distance = length
current = 0

def mark():
    global current, matrix

    matrix[coords['y']][coords['x']] = current

def step():
    global current, distance, coords, directions_sequence

    _step = directions_sequence[current_direction]
    coords['x'] += _step['x']
    coords['y'] += _step['y']
    distance -= 1
    current += 1

def rotate():
    global length, current_direction, direction_sequence

    current_direction = (current_direction + 1)%len(directions_sequence)
    if current_direction == 3 or current_direction == 1:
        length -= 1

while current < full_length:
    step()
    mark()
    if distance == 0:
        rotate()
        distance = length

for row in matrix:
    for element in row:
        print(str(element) + ' ', end='')
    print()
