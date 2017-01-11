#!/usr/bin/python3
import sys
file_name = "python_file"
file_finish = "file_finish"
total = 'item_one' + \
    'item_two' +\
    'item_three'
try:
    file = open(file_name,"w")
except IOError:
    print ("There was an error writing to",file_name)
    sys.exit()
print ("Enter '", file_finish,)
input("\n\nPress the enter key to exit.")
