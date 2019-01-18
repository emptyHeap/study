--- TRIGGERS ---
----------------

CREATE OR REPLACE FUNCTION prefill_users_knowledge_on_new_category() RETURNS trigger AS $$
BEGIN
	INSERT INTO users_questions_knowledge (user_id, question_id)
	SELECT NEW.user_id as user_id, id as question_id FROM questions WHERE NEW.category_id = questions.category_id;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS prefill_users_knowledge_on_new_category ON users_categories;
CREATE TRIGGER prefill_users_knowledge_on_new_category AFTER INSERT ON users_categories
	FOR EACH ROW EXECUTE PROCEDURE prefill_users_knowledge_on_new_category();

CREATE OR REPLACE FUNCTION prefill_users_knowledge_on_new_question() RETURNS trigger AS $$
BEGIN
	INSERT INTO users_questions_knowledge (user_id, question_id)
	SELECT
		users.id as user_id,
		NEW.id as question_id
	FROM
		users
	INNER JOIN
		users_categories
	ON
		users_categories.user_id = users.id
		AND users_categories.category_id = NEW.category_id;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS prefill_users_knowledge_on_new_question ON questions;
CREATE TRIGGER prefill_users_knowledge_on_new_question AFTER INSERT ON questions
	FOR EACH ROW EXECUTE PROCEDURE prefill_users_knowledge_on_new_question();

CREATE OR REPLACE FUNCTION prefill_users_modes_weights_on_new_user_category() RETURNS trigger AS $$
BEGIN
	INSERT INTO users_modes_weights (user_id, category_id, mode_id, weight)
	SELECT
		NEW.user_id as user_id,
		NEW.category_id as category_id,
		modes.id as mode_id,
		modes.default_weight as weight
	FROM
		modes;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS prefill_users_modes_weights_on_new_user_category ON users_categories;
CREATE TRIGGER prefill_users_modes_weights_on_new_user_category AFTER INSERT ON users_categories
	FOR EACH ROW EXECUTE PROCEDURE prefill_users_modes_weights_on_new_user_category();

CREATE OR REPLACE FUNCTION update_users_knowledge_on_answer() RETURNS trigger AS $$
BEGIN
	UPDATE
		users_questions_knowledge as uqk
	SET
		knowledge = update_knowledge(knowledge, umw.weight, options.correct)
	FROM
		questions
		INNER JOIN
			users_modes_weights as umw
			ON umw.category_id = questions.category_id
			AND umw.user_id = NEW.user_id
			AND umw.mode_id = NEW.mode_id
		INNER JOIN
			options
			ON options.id = NEW.option_id
	WHERE
		uqk.question_id = NEW.question_id
		AND uqk.user_id = NEW.user_id;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS update_users_knowledge_on_answer ON users_answers_history;
CREATE TRIGGER update_users_knowledge_on_answer AFTER INSERT ON users_answers_history
	FOR EACH ROW EXECUTE PROCEDURE update_users_knowledge_on_answer();

--- FUNCTIONS ---
-----------------

CREATE OR REPLACE FUNCTION update_knowledge (knowledge float, weight float, correct boolean) RETURNS float AS $$
DECLARE
	modified float;
BEGIN
	modified = case when correct
		then ((knowledge + sqrt(weight)/4) * (1 + weight/4))
		else (knowledge/(1 + weight/4)) end;

	RETURN case when modified > 1 then 1 else modified end;
END;
$$ LANGUAGE plpgsql;

--- PROCEDURES ---
------------------

--- CREATE OR REPLACE PROCEDURE categories_tree () LANGUAGE plpgsql AS $$
--- BEGIN
--- 	PERFORM row_to_json(categories) FROM categories;
--- 	RETURN;
--- END;
--- $$;

DROP FUNCTION IF EXISTS course_structure(integer);
CREATE OR REPLACE FUNCTION course_structure(tree_depth int) RETURNS TABLE (col json) AS $$
BEGIN
	RETURN QUERY
		SELECT
			row_to_json(category)
		FROM
			categories as category
		WHERE
			category.parent_id IS NULL;
END;
$$ LANGUAGE plpgsql;
