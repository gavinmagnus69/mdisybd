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
    id int(11) primary key auto_increment not null,
    name_program varchar(255) unique not null,
    department_id int(11) not null references department(id) on delete cascade,
    plan int(4) unsigned not null
);

CREATE TABLE enrollee(
	id INT(11) PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name_enrollee varchar(255) NOT NULL,
    user_id INT(11) unique not null references User(id) on delete cascade
);

CREATE TABLE subject(
	id INT(11) PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name_subject varchar(255) NOT NULL
);

CREATE TABLE department(
	id INT(11) PRIMARY KEY AUTO_INCREMENT NOT NULL,
    name_department varchar(255) unique NOT NULL
);

create table achievement (
	id int(11) primary key auto_increment not null,
    name_achievemnt varchar(255) not null,
    bonus int(3) unsigned not null
);


create table enrollee_achievement (
	id int(11) primary key auto_increment not null,
	enrollee_id int(11) not null references enrollee(id) on delete cascade,
	achievement_id int(11) not null references achievement(id) on delete cascade
);

create table program_enrollee (
	id int(11) primary key auto_increment not null,
	program_id int(11) not null references program(id) on delete cascade,
	enrollee_id int(11) not null references enrollee(id) on delete cascade
);

create table program_subject (
	id int(11) primary key auto_increment not null,
	program_id int(11) not null references program(id) on delete cascade,
	subject_id int(11) not null references subject(id) on delete cascade,
    min_result int(3) unsigned not null
);

create table enrollee_subject (
	id int(11) primary key auto_increment not null,
	enrollee_id int(11) not null references enrollee(id) on delete cascade,
	subject_id  int(11) not null references subject(id) on delete cascade,
    result int(3) unsigned not null
);

create table penalty (
    id int(11) primary key auto_increment not null,
	name_penalty varchar(255) unique not null,
	penalty_value  int(3) unsigned not null,
    result int(3) unsigned not null
);

create table enrollee_penalty (
	id int(11) primary key auto_increment not null,
	enrollee_id int(11) not null references enrollee(id) on delete cascade,
	penalty_id  int(11) not null references penalty(id) on delete cascade
);
