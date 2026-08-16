# Write your MySQL query statement below

select Name as Customers from Customers where Id not in (select a.Id from Customers a join Orders b on a.Id = b.CustomerId)
