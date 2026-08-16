# Write your MySQL query statement below

select S.Score, count(S2.Score) as 'Rank' from Scores S,
(select distinct Score from Scores) S2
where S.Score <= S2.Score
group by S.Id order by S.Score desc
