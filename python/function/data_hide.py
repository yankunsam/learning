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
    def displayEmployee(self):
        print "Name :",self.name, ",Salary: ",self.salary
    def displayCount(self):
        print "Count :",self.empCount

emp1 = Employee("god",1)
emp1.displayCount();
