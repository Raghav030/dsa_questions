# Write your MySQL query statement below
select ko.visited_on, sum(kp.amount) as amount, round(sum(kp.amount)/ 7, 2) as average_amount from (select distinct visited_on from customer) ko join customer kp on (datediff(ko.visited_on, kp.visited_on))<=6 and (datediff(ko.visited_on, kp.visited_on))>=0 and ko.visited_on>= (select min(visited_on)+6 from customer) group by ko.visited_on order by ko.visited_on


-- customer_id | name         | visited_on   | amount      |
-- +-------------+--------------+--------------+-------------+
-- | 1           | Jhon         | 2019-01-01   | 100         |
-- | 2           | Daniel       | 2019-01-02   | 110         | 
-- | 3           | Jade         | 2019-01-03   | 120         |

-- | 4           | Khaled       | 2019-01-04   | 130         |
-- | 5           | Winston      | 2019-01-05   | 110         | 
-- | 6           | Elvis        | 2019-01-06   | 140         | 
-- | 7           | Anna         | 2019-01-07   | 150         |
-- | 8           | Maria        | 2019-01-08   | 80          |
-- | 9           | Jaze         | 2019-01-09   | 110         | 
-- | 1           | Jhon         | 2019-01-10   | 130         | 
-- | 3           | Jade         | 2019-01-10   | 150 





-- | 2           | Daniel       | 2019-01-02   | 110         | 1           | Jhon         | 2019-01-01   | 100         |
-- | 3           | Jade         | 2019-01-03   | 120         || 1           | Jhon         | 2019-01-01   | 100         |
-- | 3           | Jade         | 2019-01-03   | 120         || 2           | Daniel       | 2019-01-02   | 110         |
-- | 3           | Jade         | 2019-01-10   | 150 
-- | 3           | Jade         | 2019-01-10   | 150 | 4           | Khaled       | 2019-01-04   | 130         |
-- | 3           | Jade         | 2019-01-10   | 150 | 5           | Winston      | 2019-01-05   | 110         | 
-- | 3           | Jade         | 2019-01-10   | 150 | 7           | Anna         | 2019-01-07   | 150         |
-- | 3           | Jade         | 2019-01-10   | 150 | 6           | Elvis        | 2019-01-06   | 140         |
-- | 3           | Jade         | 2019-01-10   | 150 
-- | 3           | Jade         | 2019-01-10   | 150 

