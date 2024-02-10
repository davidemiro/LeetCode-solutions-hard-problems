# Write your MySQL query statement below
select d.name as 'Department',e1.Name as 'Employee', e1.Salary
from Employee e1, Department d
where e1.departmentId = d.id
and 3 >
(
    select count(distinct e2.Salary)
    from Employee e2
    where e2.Salary > e1.Salary and e2.departmentId = d.id
)
;