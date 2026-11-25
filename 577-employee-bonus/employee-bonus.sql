# Write your MySQL query statement below
-- select emp.name, bonus.bonus from employee emp left join bonus on emp.empid= bonus.empid where coalesce(bonus, 100)<1000;

select name, bonus from employee left join bonus on employee.empid= bonus.empid where coalesce(bonus, 0) <1000