--1
SELECT *
FROM dep; 

--2
SELECT nome, funcao, sal, ndep 
FROM emp;

--3
SELECT *
FROM dep
ORDER BY ndep;

--4
SELECT DISTINCT funcao
FROM emp;

--5
SELECT nome, funcao, premios
FROM emp
WHERE premios IS NOT NULL;

--6
SELECT *
FROM emp
WHERE ndep IN (10, 30);

--7
SELECT nome
FROM emp
WHERE funcao = 'Analista' AND ndep = 20;

--8
nome, funcao
FROM emp
WHERE nome LIKE 'A%us%' OR nome LIKE 'R%ei%';

--9
SELECT nome, funcao, (sal * 14 + COALESCE(premios, 0)) AS "Remuneração Anual"
FROM emp;

--10
SELECT e.nome, e.sal, e.ndep, d.nome
FROM emp AS e, dep AS d
WHERE (e.nome LIKE 'A% R%') AND (e.ndep = d.ndep);

--11
SELECT e.nome, e.sal, d.nome, d.local
FROM emp AS e, dep AS d 
WHERE sal < 150000 AND e.ndep = d.ndep;

--12
SELECT DISTINCT e.funcao, dsc.escalao
FROM emp AS e
JOIN descontos AS dsc
ON e.sal BETWEEN dsc.salinf AND dsc.salsup
ORDER BY dsc.escalao, e.funcao;

--13
SELECT DISTINCT e.funcao, dsc.escalao
FROM emp AS e
JOIN descontos AS dsc
ON e.sal BETWEEN dsc.salinf AND dsc.salsup
ORDER BY dsc.escalao, e.funcao;

--14
SELECT e.nome, e.funcao, d.nome, e.sal
FROM emp AS e
JOIN descontos AS dsc
ON e.sal BETWEEN dsc.salinf AND dsc.salsup
JOIN dep AS d
ON e.ndep = d.ndep
WHERE escalao = 4;

--15
SELECT e.nome, e.funcao, e.sal, d.local
FROM emp AS e
JOIN dep AS d
ON e.ndep = d.ndep
WHERE d.local = 'Coimbra' AND e.sal > 150000;

--16
SELECT e.nome, e.funcao, dsc.escalao, d.nome
FROM emp AS e
JOIN descontos as dsc
ON e.sal BETWEEN dsc.salinf AND dsc.salsup
JOIN dep AS d
ON e.ndep = d.ndep
WHERE e.funcao != 'Continuo'
ORDER BY dsc.escalao DESC, e.nome;

--17
SELECT NULL AS NOMES, 0 AS NUMEROS
UNION ALL
SELECT 'DEPARTAMENTOS:', 1
UNION ALL
SELECT d.nome, d.ndep
FROM dep AS d
UNION ALL
SELECT NULL, 999
UNION ALL
SELECT 'EMPREGADOS:', 1000
UNION ALL
SELECT e.nome, e.nemp
FROM emp AS e
ORDER BY NUMEROS;

--18
SELECT *
from dep as d
LEFT JOIN emp AS e
ON d.ndep = e.ndep
where e.nome is NULL

--19
SELECT e.nome, e.funcao, d.local, dsc.escalao
FROM emp AS e 
JOIN dep as d ON e.ndep = d.ndep
JOIN descontos as dsc ON e.sal between dsc.salinf and dsc.salsup
WHERE  d.local like 'Coimbra' and dsc.escalao >= 2 and e.funcao like 'Vendedor'

--20
SELECT count(e.nemp)
from emp as e

--21
SELECT 
	count(nemp) as "Total de Empregados", 
	ROUND(AVG(sal),3) as "Salário médio mensal", 
	SUM(sal*14 + premios) as "Remuneração Total Anual"
from emp

--22
SELECT 
	nome,
	funcao,
	sal,
	ROUND(sal + sal*0.1355,1) AS "SALARIO_COM_AUMENTO"
FROM emp
WHERE funcao like 'Continuo'

--23
SELECT CONCAT('>>>> ', e.nome, ' ', REPEAT('<', 20-LENGTH(e.nome)))
from emp as e
order by e.nome

--24
select MIN(sal), MAX(sal), ROUND(AVG(sal),3)
from emp

--25
select funcao, count(funcao) as quantidade
from emp
where funcao like 'Analista' or funcao like '%o'
group by funcao
order by quantidade

--26
select funcao, floor(avg(sal)) as salario
from emp
group by funcao
having COUNT(1)>1
order by salario ASC

--27
select dsc.escalao, count(e.nemp)
from emp as e
join descontos as dsc on e.sal between dsc.salinf and dsc.salsup
join dep as d on e.ndep = d.ndep
where d.local like 'Coimbra'
group by dsc.escalao
order by dsc.escalao ASC

--28
SELECT d.nome, count(e.nemp), max(e.sal), min(e.sal)
from emp as e
join dep as d on e.ndep = d.ndep
group by d.ndep having avg(sal) > 200000 

--29
SELECT dsc.escalao, count(DISTINCT d.ndep)
from emp as e
join dep as d on e.ndep = d.ndep
join descontos as dsc on e.sal between dsc.salinf and dsc.salsup
group by dsc.escalao 
having dsc.escalao in (1,2,3)
order by dsc.escalao ASC

--30
SELECT e.nome, e.ndep, e.sal
from emp as e
where e.sal between 150000 and 300000

--31
SELECT e.nome, e.funcao
FROM emp AS e
WHERE e.nome LIKE '%v%' OR e.nome LIKE '%u%'

--32
SELECT e.nome, (e.sal*14 +premios)*0.1 as "10% Sal. Anual", e.premios
from emp as e
where e.premios < (e.sal*14 +premios)*0.1
order by (e.sal*14 +premios)*0.1 ASC, e.nome;

--33
SELECT e.nome, e.funcao, d.nome as NOME_DEP
from emp as e
join dep as d on e.ndep = d.ndep
order by d.nome, e.nome;

--34
SELECT e.nome, e.funcao, d.nome as NOME_DEP
from emp as e
right join dep as d on e.ndep = d.ndep
order by d.nome, e.nome;

--35
SELECT e1.nome,e2.nome, dsc.escalao, d.local
from emp as e1
join emp as e2
on e1.encar = e2.nemp
join descontos as dsc
on e1.sal between dsc.salinf and dsc.salsup
join dep as d
on e1.ndep = d.ndep
where e1.sal > 150000

--36
SELECT UPPER(e.nome), LOWER(e.funcao), INITCAP(d.nome)
FROM emp as e
join dep as d
on e.ndep = d.ndep
order by e.nome

--37
select e1.nome, e2.nome
from emp as e1
join emp as e2
on e1.nemp = e2.encar
order by e1.nome, e2.nome

--38
select count(1) as "Empregados sem premio"
from emp as e
where e.premios is null

--39
select 
	d.ndep, 
	(MAX(e.sal)-MIN(e.sal) ) as diferenca
FROM emp as e
join dep as d
on e.ndep = d.ndep
group by d.ndep
order by d.ndep

--40
select e1.nemp as Encarregado, MIN(e2.sal) as "Salario Minimo"
from emp as e1
right join emp as e2
on e1.nemp = e2.encar
group by e1.nemp
having MIN(e2.sal) > 200000 
order by MIN(e2.sal)

--41

select d.ndep, e.funcao, MAX(e.sal) as SAL_MAX, MIN(e.sal) AS SAL_MIN, FLOOR(AVG(e.sal)) AS SAL_MED, COUNT(1) AS QUANTOS
from emp as e
join dep as d
on d.ndep = e.ndep
where e.nome not like 'Jorge Sampaio'
group by d.ndep, e.funcao
having MAX(e.sal) >200000
order by ndep ASC, SAL_MAX ASC

--42 
select enc.nome, d.local, count(e.nome), sum(e.sal)
from emp as enc
join emp as e
on enc.nemp = e.encar
join dep as d
on d.ndep = e.ndep
group by enc.nome, d.local
having d.local like 'Coimbra' and count(e.nome) >1 or d.local like 'Condeixa' and count(e.nome) >1

--43
select MIN(e.sal) as SAL_MIN
from emp as e

--44
select nome, funcao, sal
from emp
where funcao = (
				SELECT funcao
				from emp
				where nome = 'Olga Costa'
				);

--45

select e.nome, e.sal, e.ndep
from emp as e
where e.sal in (
				SELECT MAX(e.sal)
				from emp as e
				join dep as d
				on d.ndep = e.ndep
				group by d.ndep
);

--46
select e.nome, e.sal, e.funcao, e.ndep
from emp as e
where e.sal > ANY (
				select e.sal
				from emp as e
				join dep as d
				on d.ndep = e.ndep
				WHERE e.ndep = 30)
order by e.sal desc

--47
select e.nome, e.sal, e.funcao, e.ndep
from emp as e
where e.sal > all (
					select e.sal
					from emp as e
					join dep as d
					on d.ndep = e.ndep
					where d.nome like 'Vendas'
)
order by e.sal ASC

--48
select e.nome, e.sal, e.funcao, d.nome
from emp as e
join dep as d
on e.ndep = d.ndep
where e.sal > (
				SELECT AVG(e.sal)
				from emp as e
				join dep as d
				on e.ndep= d.ndep
				where d.nome like 'Vendas'
				)
order by e.nome DESC;