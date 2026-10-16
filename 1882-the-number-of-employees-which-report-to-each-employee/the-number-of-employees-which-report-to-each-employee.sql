# Write your MySQL query statement below
-- with recursive numbers as (
--     select 1 as num
--     union 
--     select num+1 from numbers where num+1<=10
-- ) select * from numbers


-- select count(reports_to) from employees


-- with recursive hierarchy as (
--     select employee_id , manager_id from employees where manager is null
--     union all
--     select  employees.employee_id, managers.employee_id as maanger_id from hierarchy managers join employees employees on managers.employee_id = employees.manager_id
-- ) select * from hierarchy

-- with recursive manager_hierarchy as (
--     select employee_id, employee_name, manager_id from employees where employeename ='David'
--     union all
--     select employee.employee_id, employee.employee_name, employee.manager_id from manager_hierarchy left join employees on manager_hierarchy.manager_id = employees.employee_id where employee_id is not null
-- ) select * from manager_hierarchy

select managers.employee_id as employee_id, managers.name as name, count(employees.employee_Id) as reports_count, round(avg(employees.age)) as average_age from employees managers inner join employees employees on managers.employee_id = employees.reports_to group by employee_id, name order by employee_id