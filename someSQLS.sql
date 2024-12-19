INSERT INTO "User" (username, email, password_hash, role, created_at, updated_at) VALUES
('johndoe', 'johndoe@example.com', 'hashed_password_1', 0, DEFAULT, DEFAULT),
('janedoe', 'janedoe@example.com', 'hashed_password_2', 0, DEFAULT, DEFAULT),
('alice', 'alice@example.com', 'hashed_password_3', 0, DEFAULT, DEFAULT),
('bob', 'bob@example.com', 'hashed_password_4', 0, DEFAULT, DEFAULT);

INSERT INTO "Token" (user_id, token, expires_at) VALUES
(1, 'abc123xyz456', CURRENT_TIMESTAMP + INTERVAL '1 day'),
(2, 'def456uvw789', CURRENT_TIMESTAMP + INTERVAL '2 days'),
(3, 'ghi789rst012', CURRENT_TIMESTAMP + INTERVAL '3 days'),
(4, 'jkl012mno345', CURRENT_TIMESTAMP + INTERVAL '4 days');

INSERT INTO "department" (name_department) VALUES
('Computer Science'),
('Mathematics'),
('Physics'),
('Biology');

INSERT INTO "program" (name_program, department_id, plan) VALUES
('Computer Science Program', 1, 4),
('Mathematics Program', 2, 4),
('Physics Program', 3, 4),
('Biology Program', 4, 4);

INSERT INTO "enrollee" (name_enrollee, user_id) VALUES
('John Smith', 1),
('Jane Doe', 2),
('Alice Johnson', 3),
('Bob Brown', 4);

INSERT INTO "subject" (name_subject) VALUES
('Programming 101'),
('Calculus I'),
('Physics I'),
('Biology 101'),
('Physical education 228'),
('Chemistry 1337')
;

INSERT INTO "achievement" (name_achievement, bonus)
VALUES
    ('Olympiad ', 10),
    ('Bruh', 50),
    ('Gold medal', 25),
    ('SVO', 100),
    ('Orphant', 75);


INSERT INTO "enrollee_achievement" (enrollee_id, achievement_id)
VALUES
    (1, 1),
    (1, 2), 
    (3, 1), 
    (3, 3),  
    (2, 1), 
    (2, 4),  
    (2, 5); 

INSERT INTO "program_enrollee" (program_id, enrollee_id)
VALUES
    (1, 1), 
    (2, 2),  
    (3, 3),  
    (1, 4);  


INSERT INTO "program_subject" (program_id, subject_id, min_result)
VALUES
(1, 1, 90),
(1, 2, 90),
(1, 3, 90),
(2, 1, 95),
(2, 2, 95),
(2, 3, 95),
(3, 1, 94),
(3, 2, 94),
(3, 3, 94),
(4, 1, 80),
(4, 2, 80),
(4, 4, 90);


INSERT INTO "penalty" (name_penalty, penalty_value, result) VALUES
('Late submission', 5, 2),
('Incomplete work', 10, 5),
('Plagiarism', 20, 15),
('Missed deadline', 8, 4),
('Unauthorized collaboration', 15, 10),
('Disruptive behavior', 12, 6),
('Violation of safety rules', 25, 20),
('Improper use of equipment', 18, 12),
('Unexcused absence', 7, 3),
('Failure to follow instructions', 6, 2);



INSERT INTO "enrollee_subject" (enrollee_id, subject_id, result) VALUES
(1, 1, 90),
(1, 2, 86),
(1, 3, 93),
(1, 4, 77),
(2, 1, 99),
(2, 2, 80),
(2, 3, 90),
(2, 4, 78),
(3, 1, 90),
(3, 2, 86),
(3, 5, 99),
(3, 6, 99),
(4, 6, 90),
(4, 2, 86),
(4, 3, 93),
(4, 4, 77);


INSERT INTO "enrollee_penalty" (enrollee_id, penalty_id) VALUES
(1, 1),
(3, 7);


SELECT username FROM "User"
WHERE username LIKE 'j%';


SELECT name_achievement FROM "achievement"
WHERE bonus >= 70;

UPDATE "enrollee"
SET name_enrollee = 'Bob Sponge'
WHERE name_enrollee LIKE 'Bob Brown' ;


SELECT name_enrollee, sum(result) FROM enrollee_subject JOIN enrollee ON enrollee_subject.enrollee_id = enrollee.id
GROUP BY name_enrollee HAVING sum(result) >= 347
ORDER BY name_enrollee ASC;


SELECT name_program, ROUND(AVG(min_result), 2)
FROM program_subject JOIN program ON program.id = program_subject.program_id
GROUP BY name_program
ORDER BY name_program ASC;


DELETE "User"
WHERE id = id;


SELECT username,
    CASE
        WHEN role = 0 THEN 'student'
        WHEN role = 1 THEN 'professor'
        WHEN role = 2 THEN 'admin'
        ELSE 'unknown'
    END AS status
FROM "User";


SELECT 
    CASE 
        WHEN EXISTS (SELECT 1 FROM enrollee) 
        THEN 'We have some enrollees' 
        ELSE 'Nobody enrolled' 
    END AS results;


EXPLAIN ANALYZE SELECT * FROM User;


SELECT name_enrollee,
 name_subject,
  MAX(result) OVER (PARTITION BY enrollee_id) AS best_enrollee_result
FROM enrollee_subject es JOIN enrollee e ON es.enrollee_id = e.id JOIN subject s on es.subject_id = s.id;
