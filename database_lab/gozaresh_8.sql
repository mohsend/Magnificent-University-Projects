-----
---- گزارش کار 8
-----

USE [mohsen-db]

---
-- سوال 1
---
SELECT student.st_code, student.st_name, program.pr_name, teacher.te_name
 FROM student JOIN unit ON student.st_code = unit.st_code
   JOIN program ON unit.pr_code = program.pr_code
     JOIN teacher on program.te_code = teacher.te_code

---
-- سوال 2
---
SELECT teacher.te_name, COUNT(program.pr_code) AS erae_shode
  FROM teacher JOIN program ON program.te_code = teacher.te_code
  WHERE teacher.te_code = 1000 GROUP BY teacher.te_name

---
-- سوال 3
---
CREATE PROCEDURE sp_details @sp_id INT AS 
BEGIN
  SELECT * FROM student WHERE student.st_code = @sp_id
  SELECT unit.score, program.pr_name FROM unit
    JOIN program ON unit.pr_code = program.pr_code
  WHERE unit.st_code = @sp_id
END

EXECUTE sp_details 100

---
-- سوال 4
---
CREATE PROCEDURE num_took @dars NVARCHAR(50) AS
BEGIN
  SELECT COUNT(pr_code) FROM program JOIN lesson ON lesson.le_code = program.le_code WHERE lesson.le_name = @dars
END

execute num_took 'A'

---
-- سوال 5
---
CREATE TRIGGER num_of_vorodi ON student AFTER INSERT AS
BEGIN
  DECLARE @yr INT
  SELECT @yr = st_year FROM INSERTED
  SELECT COUNT(st_code) FROM student WHERE st_year = @yr
END

INSERT INTO student (st_code, st_name, st_year) VALUES (1010, 'TO DELETE', 1384)

---
-- سوال 6
---
CREATE TRIGGER show_del ON student AFTER DELETE AS
  SELECT * FROM DELETED

DELETE student WHERE st_code = 1010