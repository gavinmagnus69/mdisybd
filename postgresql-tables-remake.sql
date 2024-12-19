-- User table
CREATE TABLE "User" (
    id SERIAL PRIMARY KEY,
    username VARCHAR(255) NOT NULL CHECK(username != ''),
    email VARCHAR(255) UNIQUE NOT NULL CHECK(email != ''),
    password_hash VARCHAR(255) NOT NULL,
    role SMALLINT NOT NULL DEFAULT 0 CHECK(role >= 0 AND role <= 2),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Token table
CREATE TABLE "Token" (
    id SERIAL PRIMARY KEY,
    user_id INT NOT NULL,
    token VARCHAR(255) UNIQUE NOT NULL,
    expires_at TIMESTAMP NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT fk_token_user FOREIGN KEY (user_id) REFERENCES "User"(id) ON DELETE CASCADE
);

-- Department table
CREATE TABLE "department" (
    id SERIAL PRIMARY KEY,
    name_department VARCHAR(255) UNIQUE NOT NULL CHECK(name_department != '')
);

-- Program table
CREATE TABLE "program" (
    id SERIAL PRIMARY KEY,
    name_program VARCHAR(255) UNIQUE NOT NULL CHECK(name_program != ''),
    department_id INT NOT NULL,
    plan SMALLINT NOT NULL CHECK(plan >= 0),
    CONSTRAINT fk_program_department FOREIGN KEY (department_id) REFERENCES department(id) ON DELETE CASCADE
);

-- Enrollee table
CREATE TABLE "enrollee" (
    id SERIAL PRIMARY KEY,
    name_enrollee VARCHAR(255) NOT NULL CHECK(name_enrollee != ''),
    user_id INT UNIQUE NOT NULL,
    CONSTRAINT fk_enrollee_user FOREIGN KEY (user_id) REFERENCES "User"(id) ON DELETE CASCADE
);

-- Subject table
CREATE TABLE "subject" (
    id SERIAL PRIMARY KEY,
    name_subject VARCHAR(255) NOT NULL CHECK(name_subject != '')
);

-- Achievement table
CREATE TABLE "achievement" (
    id SERIAL PRIMARY KEY,
    name_achievement VARCHAR(255) NOT NULL CHECK(name_achievement != ''),
    bonus SMALLINT NOT NULL CHECK(bonus >= 0)
);

-- Enrollee Achievement table
CREATE TABLE "enrollee_achievement" (
    id SERIAL PRIMARY KEY,
    enrollee_id INT NOT NULL,
    achievement_id INT NOT NULL,
    CONSTRAINT fk_enrollee_achievement_enrollee FOREIGN KEY (enrollee_id) REFERENCES enrollee(id) ON DELETE CASCADE,
    CONSTRAINT fk_enrollee_achievement_achievement FOREIGN KEY (achievement_id) REFERENCES achievement(id) ON DELETE CASCADE
);

-- Program Enrollee table
CREATE TABLE "program_enrollee" (
    id SERIAL PRIMARY KEY,
    program_id INT NOT NULL,
    enrollee_id INT NOT NULL,
    CONSTRAINT fk_program_enrollee_program FOREIGN KEY (program_id) REFERENCES program(id) ON DELETE CASCADE,
    CONSTRAINT fk_program_enrollee_enrollee FOREIGN KEY (enrollee_id) REFERENCES enrollee(id) ON DELETE CASCADE
);

-- Program Subject table
CREATE TABLE "program_subject" (
    id SERIAL PRIMARY KEY,
    program_id INT NOT NULL,
    subject_id INT NOT NULL,
    min_result SMALLINT NOT NULL CHECK(min_result >= 0),
    CONSTRAINT fk_program_subject_program FOREIGN KEY (program_id) REFERENCES program(id) ON DELETE CASCADE,
    CONSTRAINT fk_program_subject_subject FOREIGN KEY (subject_id) REFERENCES subject(id) ON DELETE CASCADE
);

-- Enrollee Subject table
CREATE TABLE "enrollee_subject" (
    id SERIAL PRIMARY KEY,
    enrollee_id INT NOT NULL,
    subject_id INT NOT NULL,
    result SMALLINT NOT NULL CHECK(result >= 0),
    CONSTRAINT fk_enrollee_subject_enrollee FOREIGN KEY (enrollee_id) REFERENCES enrollee(id) ON DELETE CASCADE,
    CONSTRAINT fk_enrollee_subject_subject FOREIGN KEY (subject_id) REFERENCES subject(id) ON DELETE CASCADE
);

-- Penalty table
CREATE TABLE "penalty" (
    id SERIAL PRIMARY KEY,
    name_penalty VARCHAR(255) UNIQUE NOT NULL CHECK(name_penalty != ''),
    penalty_value SMALLINT NOT NULL CHECK(penalty_value >= 0),
    result SMALLINT NOT NULL CHECK(result >= 0)
);

-- Enrollee Penalty table
CREATE TABLE "enrollee_penalty" (
    id SERIAL PRIMARY KEY,
    enrollee_id INT NOT NULL,
    penalty_id INT NOT NULL,
    CONSTRAINT fk_enrollee_penalty_enrollee FOREIGN KEY (enrollee_id) REFERENCES enrollee(id) ON DELETE CASCADE,
    CONSTRAINT fk_enrollee_penalty_penalty FOREIGN KEY (penalty_id) REFERENCES penalty(id) ON DELETE CASCADE
);