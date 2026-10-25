# Write your MySQL query statement below
select id, num from (select id, num , row_number() over (order by num desc) as rn from (select id, sum(num) as num from (select requester_id as id, count(accept_date) as num from requestaccepted group by requester_id
union all select accepter_id as id, count(accept_date) as num from requestaccepted group by accepter_id)klp group by id)llp )kkp where rn=1