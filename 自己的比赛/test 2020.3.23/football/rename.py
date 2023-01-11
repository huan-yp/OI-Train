from sys import *
from os import *
suf = ".out"
pre = "football"
for i in range(3,21):
    fullname = str(i) + suf
    tofullname = pre + str(i) + suf
    popen("rename " + fullname + " " + tofullname)
