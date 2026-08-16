# Write your MySQL query statement below

select Num as ConsecutiveNums from (select distinct(a.Num) from Logs a, Logs b, Logs c where a.Id + 1 = b.Id and b.Id + 1 = c.Id and a.Num = b.Num and b.Num = c.Num) as tmp
