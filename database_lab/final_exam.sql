-----
-- امتحان پایان ترم
-- 1396/03/01
-----


-----
-- سوال 1
-----

CREATE DATABASE final_exam

USE final_exam

CREATE TABLE s
  (
   s_no VARCHAR(2) PRIMARY KEY,
   s_name VARCHAR(3),
   s_status INT,
   s_city VARCHAR(2)
  )

CREATE TABLE p
  (
   p_no VARCHAR(2) PRIMARY KEY,
   p_name VARCHAR(10),
   p_color VARCHAR(10),
   p_weight INT,
   p_city VARCHAR(2)
  )

CREATE TABLE j
  (
   j_no VARCHAR(2) PRIMARY KEY,
   j_name VARCHAR(16),
   j_city VARCHAR(2)
  )

CREATE TABLE spj
  (
   s_no VARCHAR(2) FOREIGN KEY REFERENCES s(s_no),
   p_no VARCHAR(2) FOREIGN KEY REFERENCES p(p_no),
   j_no VARCHAR(2) FOREIGN KEY REFERENCES j(j_no),
   qty INT,
   PRIMARY KEY (s_no, p_no, j_no)
  )


-- POPULATE S
INSERT INTO s VALUES ('S1', 'SN1', 20, 'C1')
INSERT INTO s VALUES ('S2', 'SN2', 10, 'C3')
INSERT INTO s VALUES ('S3', 'SN3', 30, 'C3')
INSERT INTO s VALUES ('S4', 'SN4', 20, 'C2')
INSERT INTO s VALUES ('S5', 'SN5', 30, 'C1')

-- POPULATE P
INSERT INTO p VALUES ('P1', 'nut', 'red', 12, 'C2')
INSERT INTO p VALUES ('P2', 'bolt', 'green', 17, 'C3')
INSERT INTO p VALUES ('P3', 'screw', 'blue', 17, 'C4')
INSERT INTO p VALUES ('P4', 'screw', 'red', 14, 'C2')
INSERT INTO p VALUES ('P5', 'cam', 'blue', 12, 'C3')
INSERT INTO p VALUES ('P6', 'cog', 'red', 19, 'C2')

-- POPULATE J
INSERT INTO j VALUES ('J1', 'sorter', 'C2')
INSERT INTO j VALUES ('J2', 'punch', 'C4')
INSERT INTO j VALUES ('J3', 'reader', 'C1')
INSERT INTO j VALUES ('J4', 'console', 'C1')
INSERT INTO j VALUES ('J5', 'collator', 'C2')
INSERT INTO j VALUES ('J6', 'terminal', 'C5')
INSERT INTO j VALUES ('J7', 'tape', 'C2')

-- POPULATE SPJ
INSERT INTO spj VALUES ('S1', 'P1', 'J1', 200)
INSERT INTO spj VALUES ('S1', 'P1', 'J4', 300)
INSERT INTO spj VALUES ('S2', 'P3', 'J1', 400)
INSERT INTO spj VALUES ('S2', 'P3', 'J3', 200)
INSERT INTO spj VALUES ('S2', 'P3', 'J5', 300)
INSERT INTO spj VALUES ('S3', 'P3', 'J1', 100)
INSERT INTO spj VALUES ('S3', 'P4', 'J2', 600)
INSERT INTO spj VALUES ('S4', 'P6', 'J3', 800)
INSERT INTO spj VALUES ('S5', 'P5', 'J5', 500)
INSERT INTO spj VALUES ('S5', 'P6', 'J2', 300)
INSERT INTO spj VALUES ('S5', 'P3', 'J4', 200)

-----
-- سوال 2
-----
CREATE PROCEDURE gheyrsaken AS
 SELECT j.j_no FROM
   spj INNER JOIN j ON j.j_no = spj.j_no
     INNER JOIN s ON s.s_no = spj.s_no
   WHERE s.s_city <> j.j_city GROUP BY j.j_no


EXEC gheyrsaken

-----
-- سوال 3
-----
INSERT INTO s VALUES ('S9', 'SN9', 20, 'C2')

-----
-- سوال 4
-----
-- CREATE TRIGGER
CREATE TRIGGER t10 ON s 
AFTER INSERT
AS
SELECT TOP 1 * FROM s 

-- RENAME TRIGGER
EXEC SP_RENAME 't10', 't20'

-----
-- سوال 5
-----
 SELECT spj.p_no, spj.s_no, spj.j_no, s.s_city FROM 
   spj INNER JOIN p ON spj.p_no = p.p_no 
     INNER JOIN j ON spj.j_no = j.j_no 
	   INNER JOIN s ON spj.s_no = s.s_no
  WHERE s_city = j_city AND s_city = p_city