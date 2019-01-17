DELETE FROM users_questions_knowledge;
DELETE FROM users_answers_history;
DELETE FROM users_modes_weights;
DELETE FROM users_categories;
DELETE FROM modes;
DELETE FROM users;

ALTER SEQUENCE users_questions_knowledge_id_seq RESTART;
ALTER SEQUENCE users_answers_history_id_seq RESTART;
ALTER SEQUENCE users_categories_id_seq RESTART;
ALTER SEQUENCE modes_id_seq RESTART;
ALTER SEQUENCE users_id_seq RESTART;

INSERT INTO modes (name, default_weight) VALUES
	('exam', 1),
	('prepare', 0.1);

INSERT INTO users (name) VALUES
	('masha'),
	('petia'),
	('vasia');

INSERT INTO users_categories (user_id, category_id) VALUES
	(1, 102), (1, 128), (1, 69),
	(2, 102), (2, 101),
	(3, 128), (3, 69);

INSERT INTO users_answers_history (user_id, question_id, option_id, mode_id) VALUES
	(1, 2236, 6820, 2), (1, 2239, 6893, 2), (1, 2242, 6950, 2),
	(2, 1684, 5149, 2), (2, 1685, 5169, 2), (2, 1686, 5204, 2),
	(3,  520,  729, 1), (3,  524,  854, 1), (3,  527,  929, 1);
