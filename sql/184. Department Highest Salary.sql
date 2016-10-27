# Write your MySQL query statement below
select D.Name as Department , E.Name as Employee, E.Salary as Salary
from Employee as E, (select max(Salary) as S, DepartmentId as D from Employee group by DepartmentId ) as T, Department as D
where E.Salary = T.S and E.DepartmentId = T.D and E.DepartmentId = D.Id
