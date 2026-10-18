# Write your MySQL query statement below
with recursive persons_bus as (
    select person_id, person_name, 1000-weight as rem_weight, turn from queue where turn=1
    union all
    select queue.person_id, queue.person_name, rem_weight-weight as rem_weight, queue.turn as rem_weight from queue join persons_bus where queue.turn= persons_bus.turn+1 and weight <=rem_weight) select person_name from queue where turn in (select  max(turn) from persons_bus)