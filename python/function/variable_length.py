#!/usr/bin/python
def printinfo(arg1,*vartuple):
    "This prints a variable passed arguments"
    print "Output is:"
    print arg1
    for var in vartuple:
        print var
    return
printinfo(100)
printinfo(1,2,3,4)
