#!/usr/bin/python
class Employee:
    'Common base class for all employee'
    empCount = 0
    #bahavior
    def __init__(self,name,salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1
    def displayCount(self):
        print "Total Employee %d" % Employee.empCount
    def displayEmployee(self):
        print "Name :",self.name, ",Salary: ",self.salary

emp1 = Employee("god",1)
emp2 = Employee("wade",10000000000)
'''
emp3 = Employee("kobe",3);
setattr(emp3,'age',41)
print "emp3 age:",getattr(emp3,'age')
print "emp2 age:" ,hasattr(emp2,'age')
print "emp3 age:",hasattr(emp3,'age')
delattr(emp3, 'age')
print "emp3 age:",hasattr(emp3,'age')
'''
emp1.displayEmployee()
emp2.displayEmployee()
'''
print "Employee.__doc__",Employee.__doc__

