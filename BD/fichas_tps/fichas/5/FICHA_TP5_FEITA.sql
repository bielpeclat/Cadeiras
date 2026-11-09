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
GROUP BY DP.NDEP, DP.NOME>
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

SELECT MIN(E.SAL), MAX(E.SAL)
FROM EMP E, EMP EN
WHERE E.ENCAR = EN.NEMP
GROUP BY EN.NOME
HAVIN MIN(E.SAL) >= 800
ORDER BY MIN(E.SAL);

-- ex. 6
-- Mostre o salário médio para cada tipo de função, ordenando os resultados por ordem crescente dos salários médios. O salário médio deverá ser arredondado para o menor inteiro possível que seja superior ao seu valor. Apenas deverão ser mostradas funções onde exista mais de 1 trabalhador. Mostre também o nome da função.

SELECT FUNCAO, CEIL(AVG(E.SAL))
FROM EMP E
GROUP BY E.FUNCAO
ORDER BY CEIL(AVG(E.SAL));

-- ex. 7
-- Indique o salário máximo, mínimo e médio e a quantidade de empregados para cada função e de cada departamento (grupos e subgrupos). Exclua registos individuais de nome ‘Turner’ e resultados coletivos que apresentem um salário máximo inferior ou igual a 1000. Ordene por departamento e por salário máximo.

SELECT MAX(E.SAL), MIN(E.SAL), AVG(E.SAL), COUNT(E.NEMP), D.NDEP
FROM EMP E, DEP D
WHERE D.NDEP = E.NDEP AND UPPER(E.NOME) != 'TURNER'
GROUP BY NDEP. D.NOME, E.FUNCAO
HAVING MAX(SAL) > 1000
ORDER BY D.NDEP, MAX(SAL);

-- ex. 8
-- Quantos empregados tem a empresa? E quantos trabalham no departamento de Investigacao?

SELECT 
    (SELECT COUNT (*) FROM EMP) AS TOTAL_EMPRESA
    (SELECT COUNT(*) FROM EMP E, DEP D WHERE E.NDEP = D.NDEP AND UPPER(D.NOME) = 'INVESTICACAO') AS TOTAL_INVEST
FROM DUAL;


-- ex. 9
-- Qual o salário médio dos trabalhadores e o número de trabalhadores da empresa?

SELECT 
    ROUND(AVG(E.SAL), 2) AS SAL_MEDIO,
    COUNT(*) AS N_TRABALHADORES
FROM EMP E

-- ex. 10
-- Qual o salário máximo existente na empresa, excluindo o Presidente?

SELECT MAX(E.SAL)
FROM EMP E
WHERE UPPER(E.FUNCAO) NOT LIKE 'PRESIDENTE';


-- ex. 11
-- Qual o salário médio dos trabalhadores dos departamentos de Contabilidade e Vendas?
SELECT D.NOME, ROUND(AVG(E.SAL), 2) AS SAL_MEDIO
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP AND UPPER(D.NOME) IN ('CONTABILIDADE', 'VENDAS')
GROUP BY D.NOME;


-- ex. 12
-- Quantos empregados tem cada departamento? Mostre também o número e o nome do departamento.

SELECT COUNT(E.NEMP) AS N_EMPREGADOS, D.NDEP, D.NOME
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP 
GROUP BY D.NDEP, D.NOME;

-- ex. 13
-- Qual o gasto com salários e qual o gasto com remuneraçoes (salário mensal e prémios anuais) de cada departamento?

SELECT D.NDEP, D.NOME, SUM(E.SAL) AS SOMA_SAL_GASTOS, SUM(E.SAL + NVL(E.PREMIOS, 0)) AS DIN_GASTO_SAL+PREMIOS
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP
GROUP BY D.NDEP, D.NOME;

-- ex. 14
-- Qual o nome do departamento com maior custo de salários com o pessoal?

SELECT D.NOME
FROM EMP E, DEP D
WHERE E.NDEP = D.NDEP
GROUP BY D.NOME
HAVING SUM(E.SAL) = (
    SELECT MAX(SUM(E1.SAL))
    FROM EMP E1
    GROUP BY E1.NDEP
);

-- ex. 15
-- Qual o nome do empregado mais velho da empresa?

SELECT E.NOME
FROM EMP E
WHERE E.DATA_ENTRADA = (
    SELECT MIN(E1.DATA_ENTRADA)
    FROM EMP E1
);





