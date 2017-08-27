#!/usr/bin/python
tup1 = (1,2,3)
print hex(id(tup1))
tup2 = (1,2)
tup1 = tup1 + tup2
print hex(id(tup1))
print (tup1)
