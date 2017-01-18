#!/usr/bin/python
def printme( str ):
    "This prints a passed  string into this function"
    print str
    return
'''
def changeme( mylist ):
    "This changes a passed list into this function"
    mylist.append( [ 1,2,3,4 ] )
    print "*****", "Values inside the function:", mylist, "*****"
    return
'''
#printme("hello")
def changeme( mylist ):
    "THis changes a passed list into this function"
    mylist = [ 1,2,3,4,5 ]
    print "*****", "Values inside  the function:", mylist, "*****"

mylist = [ 10,20,30 ]
changeme( mylist );
print "*****", "Values outside the function:", mylist, "*****"

