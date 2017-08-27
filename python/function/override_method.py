#!/usr/bin/python
class Employee:
    'Common base class for all employee'
    empCount = 0
    #bahavior
    def __init__(self,name,salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1
    def __del__(self):
        class_name = self.__class__.__name__
        print class_name,"destroyed!"
    def displayCount(self):
        print "Total Employee %d" % Employee.empCount
    def displayEmployee(self):
        print "Name :",self.name, ",Salary: ",self.salary
    def general(self):
        print "Yes,defined in Parent"


class Child(Employee):
    def __init__(self):
        print "Calling child constructor"
    def childMethod(self):
        print "Calling child method"
    def displayEmployee(self):
        print "Override succeed!"
emp1 = Child()

emp1.childMethod()
emp1.general()
emp1.displayEmployee()
