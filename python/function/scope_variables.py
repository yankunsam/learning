#!/usr/bin/python
total = 0;#This is global variable

def sum(arg1,arg2):
    #Add both the parameters and return them.
    total = arg1 + arg2;#Here total is local variable.
    print "Inside the function local total:",total
    return total
sum(1,1)
print "Outside the function global total: ",total
