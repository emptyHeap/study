DROP TABLE IF EXISTS Conference;
CREATE TABLE Conference(
	name TEXT,
	description TEXT
);

DROP TABLE IF EXISTS Venue;
CREATE TABLE Venue(
	id INTEGER PRIMARY KEY,
	name TEXT,
	city TEXT,
	country TEXT,
	lat NUMERIC(7,5),
	lon NUMERIC(8,5)
);

DROP TABLE IF EXISTS PaperSubmission;
CREATE TABLE PaperSubmission(
	id INTEGER PRIMARY KEY,
	conference TEXT,
	year INTEGER,
	title TEXT,
	isbn TEXT,
	page INTEGER,
	venue_id INTEGER
);
