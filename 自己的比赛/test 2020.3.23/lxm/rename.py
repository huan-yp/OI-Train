from sys import *
from os import *
suf = ".in"
pre = "lxm"
for i in range(1,11):
    fullname = str(i) + suf
    tofullname = pre + str(i) + suf
    popen("rename " + fullname + " " + tofullname)
