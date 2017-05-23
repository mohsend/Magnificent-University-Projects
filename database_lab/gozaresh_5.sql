-----
---- گزارش کار 5
-----

USE bank_db

---
-- سوال 1
---

SELECT c.name, c.family FROM customer c INNER JOIN bank b ON c.account_no = b.account_no GROUP BY c.name,c.family HAVING SUM(variz) - SUM(bardasht) > 10000

---
-- سوال 2
---

SELECT TOP 1 c.name, c.family FROM customer c INNER JOIN bank b ON c.account_no = b.account_no GROUP BY c.name,c.family ORDER BY SUM(variz) - SUM(bardasht) DESC

---
-- سوال 3
---

SELECT TOP 1 c.name, c.family FROM customer c INNER JOIN bank b ON c.account_no = b.account_no WHERE tarikh LIKE '2009%' GROUP BY c.name,c.family ORDER BY SUM(variz) - SUM(bardasht) DESC

---
-- سوال 4
---

SELECT TOP 3 c.name FROM customer c INNER JOIN bank b ON c.account_no = b.account_no GROUP BY c.name ORDER BY COUNT(b.radif) DESC
