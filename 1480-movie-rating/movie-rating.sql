# Write your MySQL query statement below
select name as results from  (select  name, row_number() over(order by count(*) desc, name asc)  as rn from movierating left join users on movierating.user_id = users.user_id group by name) kkp where rn =1
union all
select title as results from (select title, row_number() over (order by avg(rating) desc, title asc) as rn from (select movie_id, rating as rating from movierating where month(created_at)=02 and year(created_at)=2020) kkp left join movies on kkp.movie_id = movies.movie_id group by title) llp where rn=1