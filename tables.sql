CREATE TABLE User (
    id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(255) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    role TINYINT NOT NULL DEFAULT 0,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

CREATE TABLE Token (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES User(id) on delete cascade,
    token VARCHAR(255) UNIQUE NOT NULL,
    expires_at TIMESTAMP NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

create table program (
    program_id int(11) primary key auto_increment not null,
    name_program varchar(255) unique not null,
    department_id int(11) not null references test.department(department_id) on delete cascade,
    plan int(4) unsigned not null
);

CREATE TABLE enrollee(
	enrollee_id INT(11) PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name_enrollee varchar(255) NOT NULL,
    user_id INT(11) unique not null references test.User(id) on delete cascade
);

CREATE TABLE subject(
	subject_id INT(11) PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name_subject varchar(255) NOT NULL
);

CREATE TABLE department(
	department_id INT(11) PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name_department varchar(255) unique NOT NULL
);

create table achievement (
	achievement_id int(11) primary key auto_increment not null,
    bonus int(3) unsigned not null
);


create table enrollee_achievement (
	enrollee_achievement_id int(11) primary key auto_increment not null,
	enrollee_id int(11) not null references enrollee(enrollee_id) on delete cascade,
	achievement_id int(11) not null references achievement(achievement_id) on delete cascade
);

create table program_enrollee (
	program_enrollee_id int(11) primary key auto_increment not null,
	program_id int(11) not null references program(program_id) on delete cascade,
	enrollee_id int(11) not null references enrollee(enrollee_id) on delete cascade
);

create table program_subject (
	program_subject int(11) primary key auto_increment not null,
	program_id int(11) not null references program(program_id) on delete cascade,
	subject_id int(11) not null references subject(subject_id) on delete cascade,
    min_result int(3) unsigned not null
);

create table enrollee_subject (
	enrollee_subject_id int(11) primary key auto_increment not null,
	enrollee_id int(11) not null references enrollee(enrollee_id) on delete cascade,
	subject_id  int(11) not null references subject(subject_id) on delete cascade,
    result int(3) unsigned not null
);

create table penalty (
	penalty_id int(11) primary key auto_increment not null,
	name_penalty varchar(255) unique not null,
	penalty_value  int(3) unsigned not null,
    result int(3) unsigned not null
);

create table enrollee_penalty (
	enrollee_penalty_id int(11) primary key auto_increment not null,
	enrollee_id int(11) not null references enrollee(enrollee_id) on delete cascade,
	penalty_id  int(11) not null references penalty(penalty_id) on delete cascade
);
