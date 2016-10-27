# Write your MySQL query statement below
select Score, (select count(distinct Score) from Scores where Score >= S.Score) as Rank
from Scores as S
order by Score desc
