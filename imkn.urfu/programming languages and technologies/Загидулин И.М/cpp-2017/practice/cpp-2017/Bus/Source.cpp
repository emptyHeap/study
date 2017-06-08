#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#define MALE false
#define FEMALE true

enum Subject
{
	MATHS,
	MUSIC,
	PHYSICS,
	CHEMISTRY,
	BIOLOGY,
	LITERATURE,
	ENGLISH,
	HISTORY,
	SUBJECTS
};

struct Person
{
	string name;
	int age;
	bool gender;

	Person(string Name = "NoName", int Age = 0, bool Gender = MALE)
		: name(Name), age(Age), gender(Gender)
	{}

	virtual ~Person() {}

	void eat()
	{
		cout << name << ": I'm eating\n";
	}

	virtual void print()
	{
		if (gender == FEMALE)
			cout << "Girl ";
		else
			cout << "Boy ";
		cout << name << ", " << age << " years old\n";
	}

	Person createPerson(Person p)
	{
		if (gender ^ p.gender)
			return Person();
		else
			throw logic_error("Gender error!");
	}
};


// абстрактный класс
class LectureVisitor : public Person
{
public:
	LectureVisitor(string Name = "NoName", int Age = 0, bool Gender = MALE)
		: Person(Name, Age, Gender)
	{}

	virtual ~LectureVisitor() {}

	// абстрактный метод
	virtual void visitLecture() = 0;
};


class Student : public LectureVisitor
{
private:
	int kurs;
	int marks[SUBJECTS];
	double avg_mark;

public:
	Student(string Name = "NoName", int Age = 0, bool Gender = MALE, int Kurs = 1)
		: LectureVisitor(Name, Age, Gender), kurs(Kurs)
	{
		for (int i = 0; i < SUBJECTS; i++)
			marks[i] = 0;
		avg_mark = 0;
	}

	virtual ~Student() {}

	virtual void print();

	double avgMark();

	void setMark(Subject s, int value);

	void setKurs(int k);

	virtual void visitLecture()
	{
		cout << "I am sleeping\n";
	}
};


class Teacher : public LectureVisitor
{
private:
	int exp;

public:
	Teacher(string Name = "NoName", int Age = 0, bool Gender = MALE, int Exp = 1)
		: LectureVisitor(Name, Age, Gender), exp(Exp)
	{}

	virtual ~Teacher() {}

	virtual void print()
	{
		cout << "I am teacher " << name << ", my experience is " << exp << "\n";
	}

	virtual void visitLecture()
	{
		cout << "I am talking at the blackboard\n";
	}
};




void Student::setMark(Subject s, int value)
{
	if (value > 5 || value < 1)
		throw logic_error("Value must be from 1 to 5");
	marks[s] = value;
	avg_mark = -1; // средний балл нужно обновить
}


void Student::setKurs(int k)
{
	if (k > 5 || k < 1)
		throw logic_error("Kurs must be from 1 to 5");
	kurs = k;
}


double Student::avgMark()
{
	// оценки не обновлялись
	if (avg_mark >= 0)
		return avg_mark;

	// иначе пересчитываем
	double sum = 0;
	int cnt = 0;
	for (int i = 0; i < SUBJECTS; i++)
		// будем учитывать только ненулевые отметки
	if (marks[i] != 0)
	{
		sum += marks[i];
		cnt++;
	}
	if (cnt == 0) // избегаем деления на ноль
		avg_mark = 0;
	avg_mark = sum / cnt;
	return avg_mark;
}


void Student::print()
{
	cout << "I am student " << name << ", " << kurs << " kurs\n";
}


int main()
{
	LectureVisitor * man;
	man = new Student("Sasha", 20, MALE, 3);
	man->visitLecture();
	delete man;

	man = new Teacher("John", 23, MALE, 4);
	man->visitLecture();
	delete man;

	return 0;
}