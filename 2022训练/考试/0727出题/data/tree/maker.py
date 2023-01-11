
from mytool import *
"""def remove_files(files, suf=None, sub=None):
    if(not iterable(files)):
        files = [files]
    for x in files:
        if(suf is not None):
            if(get_file_suffixname(x) == suf):
                os.system("del " + x)
        elif(sub is not None):
            if(sub in x):
                os.system("del " + x)"""

name = "noi"
files=get_all_files(musts=["noi", '.out'])

#print(os.getcwd())

remove_files(files, sub=".out")
quit()



