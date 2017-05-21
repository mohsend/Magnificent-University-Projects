-----
---- گزارش کار 2
-----
CREATE DATABASE bank_db
USE bank_db

---
-- سوال 1
---

CREATE TABLE customer
  (
   account_no INT PRIMARY KEY,
   name NVARCHAR(20),
   family NVARCHAR(20),
   home_address NVARCHAR(255),
   tel VARCHAR(16),
   city NVARCHAR(16)
  )
---

CREATE TABLE bank
  (
   radif INT IDENTITY,
   account_no INT FOREIGN KEY REFERENCES customer(account_no),
   variz MONEY,
   bardasht MONEY,
   tarikh DATE
  )
---

---
-- سوال 2
---

SELECT * FROM customer ORDER BY name, family

---
-- سوال 3
---

SELECT SUM(variz) - SUM(bardasht) AS mojodi FROM bank WHERE account_no = 1234

---
-- سوال 4
---

SELECT COUNT(bardasht) FROM bank WHERE account_no = 1234

---
-- سوال 5
---

SELECT SUM(variz) FROM bank WHERE tarikh = CAST('2009-04-20' AS DATE)

---
-- سوال 6
---

SELECT SUM(variz) FROM bank WHERE account_no = 1234 AND CAST(tarikh AS VARCHAR) LIKE '2009%'

---
-- سوال 7
---

INSERT INTO bank VALUES (6, 1235, 8000, 0, '2009-04-20') -- ERROR: CAN'T INSERT TO IDENDITY

SET IDENTITY_INSERT bank ON
INSERT INTO customer (account_no) VALUES (1235)
INSERT INTO bank (radif, account_no ,variz, bardasht ,tarikh) VALUES (6, 1235, 8000, 0, '2009-04-20')

---
-- سوال 8
---

UPDATE bank SET tarikh = '2009-05-20' WHERE radif = 6

---
-- سوال 9
---

TRUNCATE TABLE bank