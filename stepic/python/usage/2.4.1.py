input_file_path = input()
result_file_path = input()
with open(input_file_path, 'r') as inp, open(result_file_path, 'w') as res:
    inp_string = inp.readlines()
    inp_string.reverse()
    res.writelines(inp_string)
