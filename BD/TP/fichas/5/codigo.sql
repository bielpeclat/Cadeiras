-- Encontre o salário mais baixo, o salário mais alto, o salário médio e a 
-- diferença entre o salário médio e o salário mais baixo e o mais alto, de todos os funcionários.
-- ex. 1

SELECT
    MIN(E.SAL)              AS SAL_MIN,
    MAX(E.SAL)              AS SAL_MAX,
    AVG(E.SAL)              AS SAL_MEDIO,
    AVG(E.SAL) - MIN(E.SAL) AS DIF_MEDIO_MIN,
    MAX(E.SAL) - AVG(E.SAL) AS DIF_MAX_MEDIO
FROM EMP E;


-- ex 2
-- Encontre a diferença entre o salário mais alto e o mais baixo para cada departamento. 
-- Mostre o número e o nome do departamento e ordene pela diferença por ordem decrescente.

SELECT DP.NDEP, DP.NOME, MAX(E.SAL) - MIN(E.SAL) AS DIF_SAL
FROM EMP E
INNER JOIN DEP DP ON DP.NDEP = E.NDEP
GROUP BY DP.NDEP, DP.NOME
ORDER BY DIF_SAL DESC;


-- ex 3
-- Mostre quantos empregados existem para cada função e 
-- o menor e o maior salário de cada função. Ordene o resultado alfabéticamente pela função.

SELECT 
    E.FUNCAO
    COUNT(E.NEMP) AS NUM_EMP, 
    MIN(E.SAL) AS MIN_SAL, 
    MAX(E.SAL) AS MAX_SAL, 
FROM EMP E
GROUP BY E.FUNCAO
ORDER BY E.FUNCAO;


-- ex. 4
-- Repita o comando anterior, mas apenas para empregados cujos 
-- nomes começam com a letra ‘S’, têm um 't' no nome e para os que têm a função de analista.

SELECT 
    E.FUNCAO
    COUNT(E.NEMP) AS NUM_EMP, 
    MIN(E.SAL) AS MIN_SAL, 
    MAX(E.SAL) AS MAX_SAL, 
FROM EMP E
WHERE E.NOME LIKE 'S%t%'
    AND UPPER(E.FUNCAO) LIKE 'ANALISTA'
GROUP BY E.FUNCAO
ORDER BY E.FUNCAO;


-- ex. 5
-- Mostre o salário mais baixo  e mais alto dos empregados que trabalham para cada Encarregado. Exclua os grupos em que o salário mínimo seja inferior a 800 e ordene o resultado por salário. Mostre também o nome do Encarregado.



