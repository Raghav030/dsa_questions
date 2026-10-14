# Write your MySQL query statement below
select contest_id, round(coalesce(count(register.user_id), 0)/ (select count(*) from users) *100, 2) as percentage from  register 
-- on users.user_id = register.user_id 
group by contest_id order by percentage desc, contest_id