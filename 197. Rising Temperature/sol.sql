# Write your MySQL query statement below

select a.Id from Weather a, Weather b where DATEDIFF(a.recordDate, b.recordDate) = 1 and a.Temperature > b.Temperature
