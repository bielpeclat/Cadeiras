-- 1.Encontre o sal�rio mais baixo, o sal�rio mais alto, o sal�rio m�dio e a diferen�a entre o sal�rio m�dio e o sal�rio mais baixo e o mais alto, de todos os funcion�rios.
SELECT MIN(SAL) AS "Salario + Baixo", MAX(SAL) AS "Salario + Alto", ROUND(AVG(SAL), 2) AS "Salario Medio", ROUND((AVG(SAL) - MIN(SAL)), 2) AS "Dif Baixo", ROUND((MAX(SAL) - AVG(SAL)), 2) AS "Dif Alto"
FROM EMP;


-- 2. Encontre a diferen�a entre o sal�rio mais alto e o mais baixo para cada departamento. Mostre o n�mero e o nome do departamento e ordene pela diferen�a por ordem decrescente.
SELECT D.NDEP, D.NOME, (MAX(SAL) - MIN(SAL)) AS Diferen�a
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP
GROUP BY D.NOME, D.NDEP
ORDER BY Diferen�a DESC;


-- 3. Mostre quantos empregados existem para cada fun��o e o menor e o maior sal�rio de cada fun��o. Ordene o resultado alfab�ticamente pela fun��o.
SELECT FUNCAO, COUNT(NEMP) AS "Num Funcionarios", MIN(SAL) AS "Sal + baixo", MAX(SAL) AS "Sal + Alto" 
FROM EMP
GROUP BY FUNCAO
ORDER BY FUNCAO;


-- 4. Repita o comando anterior, mas apenas para empregados cujos nomes come�am com a letra �S�, t�m um 't' no nome e para os que t�m a fun��o de analista.
SELECT FUNCAO, COUNT(NEMP) AS "Num Funcionarios", MIN(SAL) AS "Sal + baixo", MAX(SAL) AS "Sal + Alto" 
FROM EMP
WHERE UPPER(FUNCAO) = 'ANALISTA' AND UPPER(NOME) LIKE 'S%' AND LOWER(NOME) LIKE '%t%'
GROUP BY FUNCAO
ORDER BY FUNCAO;


-- 5. Mostre o sal�rio mais baixo e mais alto dos empregados que trabalham para cada Encarregado.
-- Exclua os grupos em que o sal�rio m�nimo seja inferior a 800 e ordene o resultado por sal�rio. Mostre tamb�m o nome do Encarregado.
SELECT EN.NOME AS "Nome do Encarregado", MIN(E.SAL) AS "Sal + baixo", MAX(E.SAL) AS "Sal + Alto" 
FROM EMP E, EMP EN
WHERE E.ENCAR = EN.NEMP
GROUP BY EN.NOME
HAVING MIN(E.SAL) >= 800
ORDER BY MIN(E.SAL);


-- 6. Mostre o sal�rio m�dio para cada tipo de fun��o, ordenando os resultados por ordem crescente dos sal�rios m�dios.
-- O sal�rio m�dio dever� ser arredondado para o menor inteiro poss�vel que seja superior ao seu valor.
-- Apenas dever�o ser mostradas fun��es onde exista mais de 1 trabalhador. Mostre tamb�m o nome da fun��o.
SELECT FUNCAO, CEIL(AVG(Sal)) AS "Salario Medio"
FROM EMP
GROUP BY FUNCAO
ORDER BY CEIL(AVG(Sal));


-- 7. Indique o sal�rio m�ximo, m�nimo e m�dio e a quantidade de empregados para cada fun��o e de cada departamento (grupos e subgrupos).
-- Exclua registos individuais de nome �Turner� e resultados coletivos que apresentem um sal�rio m�ximo inferior ou igual a 1000.
-- Ordene por departamento e por sal�rio m�ximo.
SELECT D.NDEP, D.NOME AS "Nome do Departamento", E.FUNCAO, MAX(Sal) AS "Salario + Alto", MIN(SAL) AS "Salario + Baixo", AVG(SAL) AS "Salario Medio", COUNT(NEMP) AS "Num. Funcionarios"
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP AND UPPER(E.NOME) != 'TURNER'
GROUP BY D.NDEP, D.NOME, E.FUNCAO
HAVING MAX(SAL) > 1000
ORDER BY D.NDEP, MAX(SAL);


-- 8. Quantos empregados tem a empresa? E quantos trabalham no departamento de Investigacao?
SELECT 
    (SELECT COUNT(*) FROM EMP) AS "Total_Empresa",
    (SELECT COUNT(*) FROM EMP E, DEP D WHERE E.NDEP = D.NDEP AND UPPER(D.NOME) = 'INVESTIGACAO') AS Total_Investigacao
FROM DUAL;


-- 9. Qual o sal�rio m�dio dos trabalhadores e o n�mero de trabalhadores da empresa?
SELECT COUNT(*) AS "Num. Func.", ROUND(AVG(SAL), 2) AS "Media Salarial"
FROM EMP;


-- 10. Qual o sal�rio m�ximo existente na empresa, excluindo o Presidente?
SELECT MAX(SAL)
FROM EMP
WHERE UPPER(FUNCAO) != 'PRESIDENTE'; 


-- 11. Qual o sal�rio m�dio dos trabalhadores dos departamentos de Contabilidade e Vendas?
SELECT D.NOME, ROUND(AVG(E.SAL), 2) AS "Salario Medio"
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP AND UPPER(D.NOME) IN ('CONTABILIDADE', 'VENDAS')
GROUP BY D.NOME;


-- 12. Quantos empregados tem cada departamento? Mostre tamb�m o n�mero e o nome do departamento.
SELECT D.NDEP, D.NOME, COUNT(NEMP) AS "Num. Func."
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP
GROUP BY D.NDEP, D.NOME;


-- 13. Qual o gasto com sal�rios e qual o gasto com remunera�oes (sal�rio mensal e pr�mios anuais) de cada departamento?
SELECT D.NDEP, D.NOME, SUM(E.SAL) AS "Din. Gasto. SAL", SUM(E.SAL + NVL(E.PREMIOS, 0)) AS "Din. Gasto. SAL+PREMIOS" 
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP
GROUP BY D.NDEP, D.NOME;


-- 14. Qual o nome do departamento com maior custo de sal�rios com o pessoal?
SELECT D.NOME
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP
GROUP BY D.NOME
HAVING SUM(E.SAL) = (
    SELECT MAX(SUM(E2.SAL))
    FROM EMP E2
    GROUP BY E2.NDEP
);


-- 15. Qual o nome do empregado mais velho na empresa?
SELECT NOME
FROM EMP
WHERE DATA_ENTRADA = (SELECT MIN(DATA_ENTRADA) FROM EMP);