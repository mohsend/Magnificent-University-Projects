-----
---- گزارش کار 7
-----

USE bank_db

---
-- سوال 1
---

CREATE TRIGGER mojodi ON bank AFTER INSERT AS
BEGIN
  DECLARE @ano INT
  SELECT @ano = INSERTED.account_no FROM INSERTED
  SELECT SUM(variz) - SUM(bardasht) AS mojodi FROM bank WHERE @ano = bank.account_no 
END

INSERT INTO bank (account_no ,variz, bardasht ,tarikh) VALUES (1235, 1000, 0, GETDATE())
INSERT INTO bank (account_no ,variz, bardasht ,tarikh) VALUES (1235, 0, 100, GETDATE())

---
-- سوال 2
---

CREATE TRIGGER affected_rows ON customer AFTER UPDATE AS
  SELECT @@ROWCOUNT

UPDATE customer SET tel = '021-12345678' WHERE account_no = 1235

---
-- سوال 3
---

CREATE TRIGGER account_update ON customer AFTER UPDATE AS
BEGIN
  IF UPDATE (account_no)
    SELECT @@ROWCOUNT
END

UPDATE customer SET tel = '021-87654321' WHERE account_no = 1235

UPDATE customer SET account_no = 1234 WHERE account_no = 100

---
-- سوال 4
---

CREATE TRIGGER removed_rows ON customer AFTER DELETE AS
  SELECT * FROM DELETED

DELETE customer WHERE account_no = 1234

---
-- سوال 5
---

CREATE TRIGGER allow_bardasht ON bank INSTEAD OF INSERT AS
BEGIN
  DECLARE @ano INT
  DECLARE @mojodi MONEY
  DECLARE @bar MONEY
  SELECT @ano = INSERTED.account_no FROM INSERTED
  SELECT @mojodi = SUM(variz) - SUM(bardasht) FROM bank WHERE @ano = bank.account_no 
  SELECT @bar = bardasht FROM INSERTED

  IF @mojodi > @bar
    INSERT INTO bank SELECT account_no ,variz, bardasht ,tarikh
	  FROM INSERTED
  ELSE
    SELECT 'NOT ENOUGH MOJODI'
END

INSERT INTO bank (account_no ,variz, bardasht ,tarikh) VALUES (1235, 0, 10000, GETDATE())

INSERT INTO bank (account_no ,variz, bardasht ,tarikh) VALUES (1235, 0, 100, GETDATE())

---
-- سوال 6
---

SP_HELPTEXT 'removed_rows'

---
-- سوال 7
---

ALTER TABLE customer DISABLE TRIGGER ALL