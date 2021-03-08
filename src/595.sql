# Write your MySQL query statement below
#先尝试自己写
#这个有点太简单了
#time defeat: 87.55%, space defeat: 100%
#SELECT name, population, area
#FROM World
#WHERE area > 3000000 OR population > 25000000

#尝试组合表的写法，此种在数据量大时表现更好（大雾）
#time defeat: 30.98%, space defeat: 100%
SELECT name, population, area
FROM World
WHERE area > 3000000

UNION

SELECT name, population, area
FROM World
WHERE population > 25000000
;
