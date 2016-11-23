import zipfile
import os

unpack_path = "./2.4.2"
result_file_path = "2.4.2.result"

zip_ref = zipfile.ZipFile(input(), 'r')
zip_ref.extractall(unpack_path)
zip_ref.close()

result = []

for dirpath, dirnames, filenames in os.walk(unpack_path):
    if (len(list(filter(lambda n: n[-3:] == '.py',filenames))) > 0):
        result.append(dirpath[len(unpack_path) + 1:])

result.sort()

with open(result_file_path, "w") as res:
    res.write('\n'.join(result))
