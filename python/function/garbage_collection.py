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

emp1 = Employee("god",1)
emp2 = Employee("wade",10000000000)
del emp1
#emp1.displayEmployee()
emp2.displayEmployee()
