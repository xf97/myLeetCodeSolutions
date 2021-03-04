# Write your MySQL query statement below
#不太会，先学习别人怎么写
#time defeat: 92.85%
#space defeat: 100%
#去掉最高薪资，选出来的最高就是第二高薪资
SELECT max(Salary) as SecondHighestSalary
From Employee
WHERE Salary < (SELECT max(Salary) FROM Employee)
