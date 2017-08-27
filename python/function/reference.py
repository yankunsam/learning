#!/usr/bin/python
def changeme( mylist ):
    "This changes a passed list into this function"
    mylist.append([1,2,3])
    print "Value inside the function: ",mylist
    return

mylist = [100,200,300]
changeme(mylist);
print "Value outside the function:",mylist
