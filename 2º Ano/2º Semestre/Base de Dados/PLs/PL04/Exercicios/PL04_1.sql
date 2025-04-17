SELECT UPPER(e.nome), e.funcao, d.nome
FROM emp AS e
JOIN dep AS d ON e.ndep = d.ndep
WHERE e.funcao = 'Vendedor'
ORDER BY e.nome ASC