--- CREATE DATABASE test_system;

DROP TABLE IF EXISTS users_questions_knowledge CASCADE;
DROP TABLE IF EXISTS users_categories CASCADE;
DROP TABLE IF EXISTS users_modes_weights CASCADE;
DROP TABLE IF EXISTS users_answers_history CASCADE;
DROP TABLE IF EXISTS users_quizzes CASCADE;
DROP TABLE IF EXISTS modes CASCADE;
DROP TABLE IF EXISTS options CASCADE;
DROP TABLE IF EXISTS questions_help CASCADE;
DROP TABLE IF EXISTS questions CASCADE;
DROP TABLE IF EXISTS categories CASCADE;
DROP TABLE IF EXISTS users CASCADE;

CREATE TABLE users (
	id				serial PRIMARY KEY,
	name			char(64),
	password_hash	char(1024)
);

CREATE TABLE categories (
	id				serial PRIMARY KEY,
	name			char(1024),
	description		text,
	parent_id		int,

	CONSTRAINT fk_parent_id FOREIGN KEY (parent_id) REFERENCES categories (id)
);

CREATE TABLE questions (
	id				serial PRIMARY KEY,
	text			char(4096),
	category_id		int NOT NULL,
	number			int NOT NULL,
	has_help		boolean DEFAULT false,

	CONSTRAINT fk_category_id FOREIGN KEY (category_id) REFERENCES categories (id)
);

CREATE TABLE questions_help (
	id				serial PRIMARY KEY,
	text			text,
	question_id		int NOT NULL,

	CONSTRAINT fk_question_id FOREIGN KEY (question_id) REFERENCES questions (id)
);

CREATE TABLE options (
	id				serial PRIMARY KEY,
	text			char(4096),
	correct			boolean,
	question_id		int NOT NULL,
	number			int,

	CONSTRAINT unq_question_id_number UNIQUE (question_id, number),
	CONSTRAINT fk_question_id FOREIGN KEY (question_id) REFERENCES questions (id)
);

CREATE TABLE users_quizzes (
	id				serial PRIMARY KEY,
	token			char(1024) UNIQUE,
	user_id			int NOT NULL,

	CONSTRAINT fk_user_id FOREIGN KEY (user_id) REFERENCES users (id)
);

CREATE table modes (
	id				serial PRIMARY KEY,
	name			char(256) UNIQUE,
	default_weight	float NOT NULL
);

CREATE table users_modes_weights (
	weight			float NOT NULL,
	mode_id			int NOT NULL,
	user_id			int NOT NULL,
	category_id		int NOT NULL,

	CONSTRAINT unq_mode_user_category UNIQUE (mode_id, user_id, category_id),

	CONSTRAINT fk_mode_id FOREIGN KEY (mode_id) REFERENCES modes (id),
	CONSTRAINT fk_user_id FOREIGN KEY (user_id) REFERENCES users (id),
	CONSTRAINT fk_category_id FOREIGN KEY (category_id) REFERENCES categories (id)
);

CREATE table users_answers_history (
	id				serial PRIMARY KEY,
	user_id			int NOT NULL,
	mode_id			int NOT NULL,
	question_id		int NOT NULL,
	option_id		int NOT NULL,
	created_at		date DEFAULT NOW(),

	CONSTRAINT fk_user_id FOREIGN KEY (user_id) REFERENCES users (id),
	CONSTRAINT fk_mode_id FOREIGN KEY (mode_id) REFERENCES modes (id),
	CONSTRAINT fk_option_id FOREIGN KEY (option_id) REFERENCES options (id),
	CONSTRAINT question_id FOREIGN KEY (question_id) REFERENCES questions (id)
);

CREATE table users_questions_knowledge (
	id				serial PRIMARY KEY,
	knowledge		float DEFAULT 0 NOT NULL,
	question_id		int NOT NULL,
	user_id			int NOT NULL,

	CONSTRAINT fk_question_id FOREIGN KEY (question_id) REFERENCES questions (id),
	CONSTRAINT fk_user_id FOREIGN KEY (user_id) REFERENCES users (id)
);

CREATE table users_categories (
	id				serial PRIMARY KEY,
	category_id		int NOT NULL,
	user_id			int NOT NULL,

	CONSTRAINT unq_user_category UNIQUE (user_id, category_id),

	CONSTRAINT fk_category_id FOREIGN KEY (category_id) REFERENCES categories (id),
	CONSTRAINT fk_user_id FOREIGN KEY (user_id) REFERENCES users (id)
);
