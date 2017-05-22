-----
---- گزارش کار 2
-----

USE university

---
-- سوال 1
---

SELECT major, COUNT(id) AS no_students FROM student GROUP BY major

---
-- سوال 2
---

SELECT degree, COUNT(id) AS no_students FROM student GROUP BY degree

---
-- سوال 3
---

SELECT professor_id, COUNT(name) AS no_courses FROM lessons GROUP BY professor_id

---
-- سوال 4
---

USE bank_db

SELECT account_no FROM bank GROUP BY account_no HAVING AVG(variz) > 1000

---
-- سوال 5
---

SELECT SUM(variz) - SUM(bardasht) AS mojodi FROM bank ORDER BY mojodi

---
-- سوال 6
---

SELECT bardasht FROM bank ORDER BY account_no

---
-- سوال 7
---

SELECT UPPER(name) + UPPER(family) AS upper_fullname FROM customer

---
-- سوال 8
---

UPDATE bank SET tarikh = GETDATE() WHERE tarikh = '2009-04-05'

---
-- سوال 9
---

SELECT account_no, SUM(variz) - SUM(bardasht) AS mojodi FROM bank WHERE tarikh LIKE '2009%' GROUP BY account_no

---
-- سوال 10
---

SELECT TOP 1 account_no, variz, tarikh FROM bank WHERE bardasht = 0 ORDER BY tarikh DESC