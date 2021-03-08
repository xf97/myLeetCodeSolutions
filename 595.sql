# Write your MySQL query statement below
#先尝试自己写
#这个有点太简单了
#time defeat: 87.55%, space defeat: 100%
SELECT name, population, area
FROM World
WHERE area > 3000000 or population > 25000000
