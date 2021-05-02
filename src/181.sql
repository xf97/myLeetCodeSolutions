# Write your MySQL query statement below
#假期，别整太难的
#整两个表join一下
#数据库说实话不太会，看了题解，学习了
#时间击败-59.85%，空间击败-100.00%
SELECT a.Name AS Employee
FROM Employee AS a JOIN Employee AS b
ON a.ManagerId = b.Id AND a.Salary > b.Salary
;
