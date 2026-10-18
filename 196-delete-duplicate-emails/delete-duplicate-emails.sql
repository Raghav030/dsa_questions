# Write your MySQL query statement below
delete from person where id in (select id from (select id, email, row_number() over (partition by email order by id) as rn from person)llp where rn>1)