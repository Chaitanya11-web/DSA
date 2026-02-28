# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id,Employees.name FROM Employees LEFT OUTER JOIN EmployeeUNI On EmployeeUNI.id=Employees.id;