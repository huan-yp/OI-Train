import os
from mytool.files import *

name = "random"
os.system('g++ random.cpp -o random')
files = remove_suffixname(get_all_files(os.getcwd(), ".in"))
files_in = add_suffix(files, ".in")
files_out = add_suffix(files, ".out")
print(files)
for in_file, out_file in zip(files_in, files_out):
    os.system("random < " + in_file + " > " + out_file)


