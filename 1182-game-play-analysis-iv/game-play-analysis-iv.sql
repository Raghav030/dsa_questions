# Write your MySQL query statement below
--  select player_id,   from ( select 
--  (select *, lag(event_date, 1) over (partition by player_id order by event_date) as last_played_date from activity)

select round(count(distinct case when last_played_date is not null and event_date is not null and datediff(event_date, last_played_date) =1  then player_id else null end)/ (select count(distinct player_id) from activity), 2) as fraction from (
    select *, lag(event_date, 1, null) over (partition by player_id order by event_date) as last_played_date from (select *, row_number() over (partition by player_id order by event_date) as rn from activity ) io where rn =1 or rn =2
    ) sd 
    -- where last_played_date is not null