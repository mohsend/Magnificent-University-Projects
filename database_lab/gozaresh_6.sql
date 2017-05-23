-----
---- گزارش کار 6
-----

USE bank_db

---
-- سوال 1
---

CREATE PROCEDURE in_city(@c NVARCHAR(16)) AS
  SELECT * FROM customer WHERE city = @c

EXEC in_city 'tehran'

---
-- سوال 2
---

CREATE PROCEDURE variz_day(@d DATE) AS
  SELECT customer.name, customer.family, customer.account_no
    FROM bank INNER JOIN customer ON bank.account_no = customer.account_no
    WHERE bank.tarikh = @d

EXEC variz_day '2009-04-01'

---
-- سوال 3
---

CREATE PROCEDURE add_cust AS
  INSERT INTO customer VALUES (100, 'name', 'family', NULL, NULL, NULL)

EXEC add_cust

---
-- سوال 4
---

CREATE PROCEDURE change_tel(@newtel VARCHAR(16)) AS
  UPDATE customer SET tel = @newtel WHERE account_no = 1234

EXEC change_tel '021-12345678'

---
-- سوال 5
---

CREATE PROCEDURE bardasht_city(@city NVARCHAR(16)) AS
  SELECT TOP 1 customer.name, customer.family, bank.bardasht
    FROM bank INNER JOIN customer ON bank.account_no = customer.account_no
    WHERE customer.city = @city AND bank.bardasht <> 0
	ORDER BY tarikh DESC

EXEC bardasht_city 'tehran'

---
-- سوال 6
---

CREATE PROCEDURE bardasht_more(@than MONEY) AS
  SELECT customer.*, bank.bardasht
    FROM bank INNER JOIN customer ON bank.account_no = customer.account_no
    WHERE bank.bardasht > @than

EXEC bardasht_more 1000
