commands_total = int(input())

directions = {
        'север':    [1, 0],
        'юг':       [-1, 0],
        'восток':   [0, 1],
        'запад':    [0, -1]
}
coords = [0, 0]

def move(direction, distance):
    global coords, directions

    coords = [
            coords[0] + directions[direction][0]*distance,
            coords[1] + directions[direction][1]*distance
    ]

for i in range(0, commands_total):
    command = input().split()
    direction = command[0]
    distance = int(command[1])
    move(direction, distance)

print (' '.join([str(i) for i in coords]))
