from enum import Enum

results = {}
class Results(Enum):
    games = 0
    wins = 1
    draws = 2
    looses = 3
    score = 4

games_remain = int(input())

def draw(command):
    global results

    results[command][Results.games.value] += 1
    results[command][Results.draws.value] += 1
    results[command][Results.score.value] += 1

def loose(command):
    global results

    results[command][Results.games.value] += 1
    results[command][Results.looses.value] += 1

def win(command):
    global results

    results[command][Results.games.value] += 1
    results[command][Results.wins.value] += 1
    results[command][Results.score.value] += 3

def add_command(command_name):
    global results

    if command_name in results.keys():
        return
    else:
        results[command_name] = [0, 0, 0, 0, 0]

while games_remain > 0:
    statistic = input().split(';')

    first = statistic[0]
    first_goals = int(statistic[1])
    second = statistic[2]
    second_goals = int(statistic[3])

    add_command(first)
    add_command(second)

    if (first_goals > second_goals):
        win(first)
        loose(second)
        print(first + ' won ' + second)
    elif (first_goals < second_goals):
        win(second)
        loose(first)
        print(second + ' won ' + first)
    else:
        draw(first)
        draw(second)
        print('draw ' + first + '-' + second) 

    games_remain -= 1

for team in results:
    print(team, end=':')
    for stat in results[team]:
        print(str(stat), end=' ')
    print()
