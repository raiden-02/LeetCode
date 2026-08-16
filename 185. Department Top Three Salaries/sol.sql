# Write your MySQL query statement below

select Dep.name as "Department", Emp.name as "Employee", Emp.salary as "Salary" from Employee Emp join Department Dep on Emp.departmentId = Dep.id 
where 3 > (select count(distinct Emp2.salary) from Employee Emp2 where Emp.departmentId = Emp2.departmentId and Emp2.salary > Emp.salary)
