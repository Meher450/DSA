# Write your MySQL query statement below
select firstName, lastName, city ,state 
FROM Person LEFT join Address on Person.personId=Address.personId;