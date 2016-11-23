file_path = 'dataset_3380_5.txt'
results = [[] for i in range(0,11)];

with open(file_path, 'r') as tsv:
    for line in tsv.readlines():
        info = line.split()
        grade = int(info[0])
        family = info[1]
        height = int(info[2])

        results[grade - 1].append(height)

for i, result in enumerate(results):
    grade = str(i + 1) + ' '
    if len(result) == 0:
        print(grade + '-')
    else:
        print(grade + str(float(sum(result))/len(result)))
    
