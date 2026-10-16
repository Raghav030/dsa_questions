# Write your MySQL query statement below
select x, y, z, case when (x+y)<=z or (y+z)<=x or (x+z)<=y or abs(x-y)>=z or abs(x-z)>=y or abs(y-z)>=x then 'No' Else 'Yes' end as triangle from triangle