# Write your MySQL query statement below
select * from users where lower(mail) regexp '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$'  AND mail LIKE BINARY '%@leetcode.com';
