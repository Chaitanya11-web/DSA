# Write your MySQL query statement below

#writing Max(e.salary) is useless because we can't write aggregate function like this

-- SELECT d.name as Department,e.name as Employee,e.salary
-- FROM Employee e JOIN Department d
-- ON e.departmentId=d.id
-- GROUP BY e.departmentId
-- HAVING MAX(e.salary);

SELECT  d.name as Department,e.name as Employee,e.salary
FROM Employee e JOIN Department d
ON e.departmentId=d.id 
#agar d.name nhi rakhenge to vo salary bhi aa jaayegi jo dusre dept me max na ho...check below
WHERE (e.salary,d.name) IN(
SELECT MAX(e.salary),d.name
FROM Employee e JOIN Department d
ON e.departmentId=d.id
GROUP BY e.departmentId);

-- Input
-- Employee =
-- | id | name | salary | departmentId |
-- | -- | ---- | ------ | ------------ |
-- | 1  | Joe  | 60000  | 1            |
-- | 2  | Sam  | 50000  | 1            |
-- | 4  | Max  | 50000  | 2            |
-- Department =
-- | id | name |
-- | -- | ---- |
-- | 1  | IT   |
-- | 2  | HR   |

-- Use Testcase
-- Output
-- | Department | Employee | salary |
-- | ---------- | -------- | ------ |
-- | IT         | Joe      | 60000  |
-- | IT         | Sam      | 50000  |
-- | HR         | Max      | 50000  |