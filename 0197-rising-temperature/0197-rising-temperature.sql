# Write your MySQL query statement below
select w2.id from weather w1
cross join weather w2
where w2.recordDate=w1.recordDate + INTERVAL 1 DAY and w1.temperature < w2.temperature