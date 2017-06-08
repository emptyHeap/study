#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;


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

	Person* next = nullptr;

	Person(string Name = "NoName", int Age = 0, bool Gender = false)
		: name(Name), age(Age), gender(Gender)
	{}

	void eat()
	{
		cout << name << ": I'm eating\n";
	}

	void print()
	{
		if (gender == true)
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

class Student : public Person
{
private:
	// теперь пол€ класса Student закрыты от внешнего доступа
	int kurs;
	int marks[SUBJECTS];
	// чтобы не пересчитывать средний балл, будем его хранить
	double avg_mark;

public:
	Student(string Name = "NoName", int Age = 0, bool Gender = false, int Kurs = 1)
		: Person(Name, Age, Gender), kurs(Kurs)
	{
		for (int i = 0; i < SUBJECTS; i++)
			marks[i] = 0;

		avg_mark = 0;
	}

	void print()
	{
		Person::print();
		cout << "I am student " << kurs << " kurs with avg_mark = " << avgMark() << endl;
	}

	double avgMark()
	{
		// оценки не обновл€лись
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

		if (cnt == 0) // избегаем делени€ на ноль
			avg_mark = 0;

		avg_mark = sum / cnt;

		return avg_mark;
	}

	void setMark(Subject s, int value)
	{
		if (value > 5 || value < 1)
			throw logic_error("Value must be from 1 to 5");

		marks[s] = value;

		avg_mark = -1; // средний балл нужно обновить
	}

	// поле  ”–— теперь закрыто
	// разрешаем изменение данных только через методы
	void setKurs(int k)
	{
		if (k > 5 || k < 1)
			throw logic_error("Kurs must be from 1 to 5");

		kurs = k;
	}

	int getKurs()
	{
		return kurs;
	}
};

template <class T>
void my_sort<T>(T *arr, int count)
{
	for (int i = 1; i < count - 1; i++)
		for (int j = 0; j < count - i; j++)
		{
			if (arr[j] > arr[j + 1])
				continue;

			T temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = arr;
		}
}

int main()
{
	ifstream f_in("students.txt");
	Student students[100];
	int students_count = 0;

	f_in >> students_count;

	for (int i = 0; i < students_count; i++)
	{
		f_in >> students[i].name >> students[i].age >> students[i].gender;
		
		int year;
		f_in >> year;
		students[i].setKurs(year);

		int mark = 0;
		for (int j = 0; j < SUBJECTS; j++)
		{
			f_in >> mark;
			students[i].setMark(static_cast<Subject>(j), mark);
		}
	}

	
	for (int i = 1; i < students_count - 1; i++)
		for (int j = 0; j < students_count - i; j++)
		{
			if (students[j].avgMark() > students[j + 1].avgMark())
				continue;

			Student temp = students[j];
			students[j] = students[j + 1];
			students[j + 1] = temp;
		}

	int year;
	cout << "Enter student's year:\n";
	cin >> year;
	// запись в файл
	ofstream f_out("selected.txt");

	for (int i = 0; i < students_count; i++)
	{
		if (students[i].getKurs() != year)
			continue;

		students[i].print();

		f_out << students[i].name << " "
			<< students[i].age << " "
			<< students[i].gender << " "
			<< students[i].getKurs() << endl;
	}

	f_out.close();

	return 0;
}