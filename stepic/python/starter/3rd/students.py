#subjects = {
#        'math': [],
#        'physics': [],
#        'russian': []
#}
#
#with open('dataset_3363_4.txt', 'r') as dataset:
#    with open('result_3363_4.txt', 'w') as result:
#        for line in dataset.readlines():
#            student_info = line.split(';')
#            subjects['math'].append(student_info[1])
#            subjects['physics'].append(student_info[2])
#            subjects['russian'].append(student_info[3])

subjects = [[] for i in range(0, 3)]
with open('result_3363_4.txt', 'w') as result:
    with open('dataset_3363_4.txt', 'r') as dataset:
        for line in dataset.readlines():
            grades = [float(grade) for grade in line.split(';')[1:]] 
            result.write(str(sum(grades)/len(grades)) + '\n')
            for i, grade in enumerate(grades):
                subjects[i].append(grade)
    for grades in subjects:
        result.write(str(sum(grades)/len(grades)) + ' ')
