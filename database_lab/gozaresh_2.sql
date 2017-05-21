-----
---- گزارش کار 2
-----
USE university

---
-- سوال 1
--- در سوال 7 گزارش کار 1 انجام شده

---
-- سوال 2
---

SELECT * FROM student WHERE enter_year = 1384

---
-- سوال 3
---

SELECT * FROM professor WHERE name LIKE 'a%'

---
-- سوال 4
---

SELECT COUNT(*) FROM student WHERE enter_year = 1384

---
-- سوال 5
---

SELECT SUM(ncourse) FROM lessons WHERE student_id = 1

---
-- سوال 6
---

SELECT * FROM lessons WHERE ncourse <> 3

---
-- سوال 7
---

SELECT TOP 3 * FROM student

---
-- سوال 8
---
-- ستون مربوط به شماره شناسنامه در گزارش قبلی پاک شد. اگر بود:

SELECT * FROM student WHERE shenasname = 0

---
-- سوال 9
---

ALTER TABLE student ADD tel VARCHAR(16)

---
-- سوال 10
---

SELECT * FROM student WHERE tel <> '0511-123456'

SELECT * FROM student WHERE tel LIKE '0[0-9][0-9][0-9]-[0-9][0-9][0-9][0-9][0-9][0-9]'