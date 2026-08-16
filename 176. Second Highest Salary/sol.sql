# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary from Employee where Salary not in (select max(Salary) from Employee)


# Write your MySQL query statement below

-- --- alternate solution ---

select ifnull((select distinct Salary from Employee order by Salary desc limit 1 offset 1), null) as SecondHighestSalary
