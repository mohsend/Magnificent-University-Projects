-----
---- گزارش کار 1
-----

---
-- سوال 1
---
CREATE DATABASE university
USE university
---

CREATE TABLE student 
  (
   id INT PRIMARY KEY,
   name NVARCHAR(20) NULL,
   family NVARCHAR(20) NULL,
   father_name NVARCHAR(20) NULL,
   major NVARCHAR(20) NULL,
   degree NVARCHAR(3) NULL,
   enter_year INT NULL
  )
---

CREATE TABLE professor
  (
   id INT PRIMARY KEY,
   name NVARCHAR(20),
   family NVARCHAR(20),
   degree NVARCHAR(3)
  )
---

CREATE TABLE lesson
  (
   id INT PRIMARY KEY,
   name NVARCHAR(20),
   course INT,
   student_id INT FOREIGN KEY REFERENCES student(id),
   professor_id INT FOREIGN KEY REFERENCES professor(id)
  )
---

INSERT INTO student VALUES (1, 'ali', 'rezaee', 'mohammad', 'IT', 'BS', 1386)
INSERT INTO student VALUES (2, 'sarah', 'alavi', 'ali', 'IT', 'BS', 1385)
INSERT INTO student VALUES (3, 'zahra', 'sadeghi', 'hassan', 'IT', 'BS', 1386)
INSERT INTO student VALUES (4, 'samira', 'fatemi', 'ali', 'IT', 'BS', 1384)
---

INSERT INTO professor VALUES (1, 'ali', 'akbari', 'PhD')
INSERT INTO professor VALUES (2, 'fatemeh', 'sedaghati', 'PhD')
INSERT INTO professor VALUES (3, 'sarah', 'sadeghi', 'PhD')
---

INSERT INTO lesson VALUES (1, 'mathematics', 3, 1, 3)
INSERT INTO lesson VALUES (2, 'physics', 3, 1, 3)
INSERT INTO lesson VALUES (3, 'database', 3, 1, 3)
INSERT INTO lesson VALUES (4, 'operating system', 3, 1, 3)

---
-- سوال 3
---

SP_DEPENDS 'lessons' -- NO ERRORS

SP_RENAME 'lesson', 'lessons'

---
-- سوال 4
---

ALTER TABLE student ALTER COLUMN id BIGINT -- ERROR: lesson.student_id DEPENDS ON IT

-- FIX
ALTER TABLE lessons DROP CONSTRAINT FK__lesson__student___145C0A3F
ALTER TABLE student DROP CONSTRAINT PK__student__3213E83F5DD68900
ALTER TABLE student ALTER COLUMN id BIGINT -- ERROR: lesson.student_id DEPENDS ON IT
ALTER TABLE lessons ALTER COLUMN student_id BIGINT

---
-- سوال 5
---

ALTER TABLE lessons ALTER COLUMN name NVARCHAR(50)

---
-- سوال 6
---

ALTER TABLE student ADD shenasname INT DEFAULT 0 WITH VALUES

---
-- سوال 7
---

ALTER TABLE student DROP COLUMN shenasname -- The object 'DF__student__shenasn__1920BF5C' is dependent on column 'shenasname'.
-- The default value is an object depending on the column 
-- FIX
ALTER TABLE student DROP CONSTRAINT DF__student__shenasn__1920BF5C
ALTER TABLE student DROP COLUMN shenasname -- Command(s) completed successfully.

---
-- سوال 8
---

EXEC SP_RENAME 'lessons.course', 'ncourse', 'COLUMN'

