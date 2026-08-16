# Write your MySQL query statement below

select name, bonus from Employee a left join Bonus b on a.empId = b.empId where bonus is null or bonus < 1000
