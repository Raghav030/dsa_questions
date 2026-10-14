# Write your MySQL query statement below
select signups.user_id, round(avg(case when action = 'confirmed' then 1 else 0 end),2)
-- / coalesce(count(1), 1), 2) 
as confirmation_rate 
from signups left join confirmations on signups.user_id = confirmations.user_id group by signups.user_id