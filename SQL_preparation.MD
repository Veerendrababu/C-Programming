
# SQL Interview Preparation

## Table of Contents

1. [DISTINCT](#1-distinct)
2. [NOT](#2-not)
3. [LIKE](#3-like)
4. [IS NULL](#4-is-null)
5. [IS NOT NULL](#5-is-not-null)
6. [SELECT TOP 3](#6-select-top-3)
7. [IN](#7-in)
8. [BETWEEN](#8-between)
9. [Aliases](#9-aliases)
10. [Aggregate Functions](#10-aggregate-functions)
11. [JOINS](#11-joins)
12. [CASE Statements](#12-case-statements)
13. [CONCAT](#13-concat)
14. [DDL, DML, and DQL](#14-ddl-dml-and-dql)
15. [Subqueries](#15-subqueries)
16. [Set Functions](#16-set-functions)
17. [Substrings](#17-substrings)

### 1. **DISTINCT**
**Question**: What is the purpose of the `DISTINCT` keyword in SQL?
**Answer**: The `DISTINCT` keyword is used to remove duplicate rows from the result set of a SELECT query, returning only unique values.

**Example**:
```sql
SELECT DISTINCT department_id
FROM employees;
```

### 2. **NOT**
**Question**: How do you use the `NOT` operator in SQL?
**Answer**: The `NOT` operator is used to negate a condition in a query.

**Example**:
```sql
SELECT *
FROM employees
WHERE NOT department_id = 1;
```

### 3. **LIKE**
**Question**: How does the `LIKE` operator work in SQL?
**Answer**: The `LIKE` operator is used for pattern matching in SQL, typically with wildcards `%` (zero or more characters) and `_` (a single character).

**Example**:
```sql
SELECT *
FROM employees
WHERE first_name LIKE 'J%';
```

### 4. **IS NULL**
**Question**: How do you check for NULL values in SQL?
**Answer**: You use the `IS NULL` condition to check for NULL values.

**Example**:
```sql
SELECT *
FROM employees
WHERE department_id IS NULL;
```

### 5. **IS NOT NULL**
**Question**: How do you check for non-NULL values in SQL?
**Answer**: You use the `IS NOT NULL` condition to check for non-NULL values.

**Example**:
```sql
SELECT *
FROM employees
WHERE department_id IS NOT NULL;
```

### 6. **SELECT TOP 3**
**Question**: How do you select the top N rows in SQL?
**Answer**: You can use the `LIMIT` clause in MySQL/PostgreSQL or `TOP` in SQL Server to select the top N rows.

**Example**:
```sql
-- MySQL/PostgreSQL
SELECT *
FROM employees
ORDER BY salary DESC
LIMIT 3;

-- SQL Server
SELECT TOP 3 *
FROM employees
ORDER BY salary DESC;
```

### 7. **IN**
**Question**: How does the `IN` operator work in SQL?
**Answer**: The `IN` operator allows you to specify multiple values in a `WHERE` clause.

**Example**:
```sql
SELECT *
FROM employees
WHERE department_id IN (1, 2, 3);
```

### 8. **BETWEEN**
**Question**: How do you use the `BETWEEN` operator in SQL?
**Answer**: The `BETWEEN` operator is used to filter the result set within a certain range.

**Example**:
```sql
SELECT *
FROM salaries
WHERE salary BETWEEN 50000 AND 80000;
```

### 9. **Aliases**
**Question**: What is the purpose of using aliases in SQL?
**Answer**: Aliases are used to give a table or a column a temporary name for the duration of a query, which makes the query easier to read and write.

**Example**:
```sql
SELECT e.first_name AS fname, e.last_name AS lname
FROM employees e;
```

### 10. **Aggregate Functions**
**Question**: What are aggregate functions in SQL?
**Answer**: Aggregate functions perform a calculation on a set of values and return a single value. Common aggregate functions include `SUM()`, `AVG()`, `COUNT()`, `MAX()`, and `MIN()`.

**Example**:
```sql
SELECT AVG(salary) AS average_salary
FROM salaries;
```

### 11. **JOINS**
**Question**: What are the different types of joins in SQL?
**Answer**: The main types of joins are:
- **INNER JOIN**: Returns records that have matching values in both tables.
- **LEFT JOIN**: Returns all records from the left table, and the matched records from the right table.
- **RIGHT JOIN**: Returns all records from the right table, and the matched records from the left table.
- **FULL JOIN**: Returns all records when there is a match in either left or right table.

**Example**:
```sql
-- Inner Join
SELECT e.first_name, e.last_name, d.department_name
FROM employees e
INNER JOIN departments d ON e.department_id = d.department_id;
```

### 12. **CASE Statements**
**Question**: How do you use the `CASE` statement in SQL?
**Answer**: The `CASE` statement is used to add conditional logic to SQL queries.

**Example**:
```sql
SELECT first_name, last_name,
       CASE
           WHEN salary >= 80000 THEN 'High'
           WHEN salary >= 60000 THEN 'Medium'
           ELSE 'Low'
       END AS salary_grade
FROM employees e
JOIN salaries s ON e.emp_id = s.emp_id;
```

### 13. **CONCAT**
**Question**: How do you concatenate strings in SQL?
**Answer**: You use the `CONCAT` function to combine two or more strings into one.

**Example**:
```sql
SELECT CONCAT(first_name, ' ', last_name) AS full_name
FROM employees;
```

### 14. **DDL, DML, and DQL**
**Question**: What are DDL, DML, and DQL in SQL?
**Answer**:
- **DDL (Data Definition Language)**: Commands that define the structure of the database (e.g., `CREATE`, `ALTER`, `DROP`).
- **DML (Data Manipulation Language)**: Commands that manipulate data within the database (e.g., `INSERT`, `UPDATE`, `DELETE`).
- **DQL (Data Query Language)**: Commands that query the database (e.g., `SELECT`).

**Examples**:
```sql
-- DDL
CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    department_id INT
);

-- DML
INSERT INTO employees (emp_id, first_name, last_name, department_id)
VALUES (1, 'John', 'Doe', 1);

-- DQL
SELECT first_name, last_name
FROM employees;
```

### 15. **Subqueries**
**Question**: What is a subquery in SQL?
**Answer**: A subquery is a query within another query. It can be used to return data that will be used in the main query as a condition to further restrict the data to be retrieved.

**Example**:
```sql
SELECT first_name, last_name
FROM employees
WHERE department_id = (SELECT department_id
                       FROM departments
                       WHERE department_name = 'HR');
```

### 16. **Set Functions**
**Question**: What are set functions in SQL and give an example?
**Answer**: Set functions perform operations on multiple sets of data. Common set functions include `UNION`, `INTERSECT`, and `EXCEPT` (or `MINUS` in Oracle).

**Example**:
```sql
-- Union
SELECT first_name FROM employees
UNION
SELECT first_name FROM clients;

-- Intersect (not supported by all DBMS)
SELECT first_name FROM employees
INTERSECT
SELECT first_name FROM clients;

-- Except (Minus in Oracle)
SELECT first_name FROM employees
EXCEPT
SELECT first_name FROM clients;
```

### 17. **Substrings**
**Question**: How do you extract a substring in SQL?
**Answer**: You use the `SUBSTRING` function to extract a part of a string.

**Example**:
```sql
SELECT SUBSTRING(first_name, 1, 3) AS short_name
FROM employees;
```

### Practice Questions

1. **DISTINCT**: Write a query to get distinct department IDs from the employees table.
   ```sql
   SELECT DISTINCT department_id FROM employees;
   ```

2. **NOT**: Write a query to get all employees who are not in department 1.
   ```sql
   SELECT * FROM employees WHERE NOT department_id = 1;
   ```

3. **LIKE**: Write a query to find employees whose first name starts with 'A'.
   ```sql
   SELECT * FROM employees WHERE first_name LIKE 'A%';
   ```

4. **IS NULL**: Write a query to find employees who do not have a department assigned.
   ```sql
   SELECT * FROM employees WHERE department_id IS NULL;
   ```

5. **IS NOT NULL**: Write a query to find employees who have a department assigned.
   ```sql
   SELECT * FROM employees WHERE department_id IS NOT NULL;
   ```

6. **SELECT TOP 3**: Write a query to find the top 3 highest-paid employees.
   ```sql
   SELECT * FROM employees ORDER BY salary DESC LIMIT 3; -- MySQL/PostgreSQL

   -- SQL Server
   -- SELECT TOP 3 * FROM employees ORDER BY salary DESC;
   ```

7. **IN**: Write a query to find employees in departments 1, 2, and 3.
   ```sql
   SELECT * FROM employees WHERE department_id IN (1, 2, 3);
   ```

8. **BETWEEN**: Write a query to find employees with salaries between 50000 and 80000.
   ```sql
   SELECT * FROM salaries WHERE salary BETWEEN 50000 AND 80000;
   ```

9. **Aliases**: Write a query to select employee names with aliases.
   ```sql
   SELECT e.first_name AS fname, e.last_name AS lname FROM employees e;
   ```

10. **Aggregate Functions**:

 Write a query to get the average salary of employees.
    ```sql
    SELECT AVG(salary) AS average_salary FROM salaries;
    ```

11. **JOINS**: Write a query to list employees with their department names.
    ```sql
    SELECT e.first_name, e.last_name, d.department_name
    FROM employees e
    INNER JOIN departments d ON e.department_id = d.department_id;
    ```

12. **CASE Statements**: Write a query to categorize employees based on their salary.
    ```sql
    SELECT first_name, last_name,
           CASE
               WHEN salary >= 80000 THEN 'High'
               WHEN salary >= 60000 THEN 'Medium'
               ELSE 'Low'
           END AS salary_grade
    FROM employees e
    JOIN salaries s ON e.emp_id = s.emp_id;
    ```

13. **CONCAT**: Write a query to concatenate first and last names of employees.
    ```sql
    SELECT CONCAT(first_name, ' ', last_name) AS full_name FROM employees;
    ```

14. **DDL**: Write a query to create a table named `projects`.
    ```sql
    CREATE TABLE projects (
        project_id INT PRIMARY KEY,
        project_name VARCHAR(100)
    );
    ```

15. **DML**: Write a query to insert a new employee.
    ```sql
    INSERT INTO employees (emp_id, first_name, last_name, department_id)
    VALUES (1, 'John', 'Doe', 1);
    ```

16. **DQL**: Write a query to select all employees.
    ```sql
    SELECT first_name, last_name FROM employees;
    ```

17. **Subqueries**: Write a query to find employees in the 'HR' department using a subquery.
    ```sql
    SELECT first_name, last_name
    FROM employees
    WHERE department_id = (SELECT department_id
                           FROM departments
                           WHERE department_name = 'HR');
    ```

18. **Set Functions**: Write a query to get the union of employee and client first names.
    ```sql
    SELECT first_name FROM employees
    UNION
    SELECT first_name FROM clients;
    ```

19. **Substrings**: Write a query to get the first three letters of employee first names.
    ```sql
    SELECT SUBSTRING(first_name, 1, 3) AS short_name FROM employees;
    ```

By reviewing these questions and examples, you'll be well-prepared to answer questions on these SQL concepts in an interview.