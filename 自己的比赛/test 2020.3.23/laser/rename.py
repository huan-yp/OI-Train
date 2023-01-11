from sys import *
from os import *
suf = ".in"
pre = "laser"
for i in range(1,21):
    fullname = str(i) + suf
    tofullname = pre + str(i) + suf
    popen("rename " + fullname + " " + tofullname)
