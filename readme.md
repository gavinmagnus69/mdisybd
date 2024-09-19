Система поступления в ВУЗ
Ахметов Роман 253502

department:
	department_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	name_department varchar(255) not null
subject:
	subject_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	name_subject varchar(255) not null
enrollee:
	name_enrollee varchar(255) not null
	user_id INT FOREIGN KEY user(user_id) not null LENGTH(11) 
achievement:
	achievement_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	bonus INT UNSIGNED not null LENGTH(3)
user:
	user_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	email varchar(255) not null
	password_hash varchar(255) not null
	role int unsigned not null length(1) default 0
	created_at timestamp default current_timestamp not null
	updated_at timestamp default current_timestamp not null
program:
	program_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	name_program varchar(255) not null
	department_id INT FOREIGN KEY department(department_id) not null LENGTH(11) 
	plan int unsigned not null length(4)
enrollee_achievement:
	enrollee_achievement_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	enrollee_id INT FOREIGN KEY enrollee(enrollee_id) not null LENGTH(11) 
	achievement_id INT FOREIGN KEY achievement(achievement_id) not null LENGTH(11) 
token:
	token_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	user_id INT FOREIGN KEY user(user_id) not null LENGTH(11) 
	token varchar(255) not null
	expires_at timestamp default current_timestamp not null
	updated_at timestamp default current_timestamp not null
program_enrollee:
	program_enrollee_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	program_id INT FOREIGN KEY program(program_id) not null LENGTH(11) 
	enrollee_id INT FOREIGN KEY enrollee(enrollee_id) not null LENGTH(11) 
program_subject:
	program_subject_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	program_id INT FOREIGN KEY program(program_id) not null LENGTH(11) 
	subject_id INT FOREIGN KEY subject(subject_id) not null LENGTH(11) 
	min_result int unsigned not null length(3)
enrollee_subject:
	enrollee_subject_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	enrollee_id INT FOREIGN KEY enrollee(enrollee_id) not null LENGTH(11) 
	subject_id INT FOREIGN KEY subject(subject_id) not null LENGTH(11) 
	result int unsigned not null length(3)
penalty:
	penalty INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	name_penalty varchar(255) not null
	penalty_value int unsigned not null length(3)
enrollee_penalty:
	enrollee_penalty_id INT PRIMARY KEY AUTO INCREMENT NOT NULL LENGTH(11)
	enrollee_id INT FOREIGN KEY enrollee(enrollee_id) not null LENGTH(11) 
	penalty_id INT FOREIGN KEY penalty(penalty_id) not null LENGTH(11) 

	

