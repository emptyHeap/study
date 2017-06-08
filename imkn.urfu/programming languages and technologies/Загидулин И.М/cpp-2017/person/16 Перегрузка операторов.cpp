#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
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
		//   0 1
		// 0 0 1
		// 1 1 0
        if (gender ^ p.gender)
            return Person();
        else
            throw logic_error("Gender error!");
    }

    // перегрузка оператора +
    Person operator+ (Person p)
    {
        return createPerson(p);
    }
	
};


class LectureVisitor : public Person
{
protected:
    double money;

public:
    LectureVisitor(string Name = "NoName", int Age = 0, bool Gender = MALE)
        : Person(Name, Age, Gender), money(0.0)
    {}

    virtual ~LectureVisitor() {}

    // посетить лекцию
    virtual void visitLecture() = 0;

    // рейтинг требуется для получения гранта
    virtual double getRating() = 0;

    // увеличивает баланс
    virtual void addMoney(double value) = 0;
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

    void print();

    double avgMark();

    void setMark(Subject s, int value);

    void setKurs(int k);

    double getRating()
    {
        return avgMark() * 0.2;
    }

    virtual void visitLecture()
    {
        cout << "I am sleeping\n";
    }

    void addMoney(double value)
    {
        // внутри класса определен указатель на текущий объект this
        this->money += value;
        cout << "Cool! Let's buy a new car!\n";
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

    void print()
    {
        cout << "I am teacher " << name << ", my experience is " << exp << "\n";
    }

    void visitLecture()
    {
        cout << "I am talking at the blackboard\n";
    }

    double getRating()
    {
        return exp * 0.1;
    }

    void addMoney(double value)
    {
        // внутри класса определен указатель на текущий объект this
        this->money += value;
        cout << "I have a lot of money. I can take a vacation.\n";
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


// спонсоры будут начислять гранты студентам и преподавателям
class Sponsor
{
private:
    // класс вектор из стандартной библиотеки
    vector<LectureVisitor*> people;

    void pay(LectureVisitor* man)
    {
        if (man->getRating() > 0.9)
		{
			man->print();
            man->addMoney(1000000);
		}
    }

public:

    // конструктор
    Sponsor()
    {
        readStudents("students.txt");
        readTutors("teachers.txt");
    }

    // очищаем динамически выделенную память
    ~Sponsor()
    {
        for (int i = 0; i < people.size(); i++)
            delete people[i];
    }

    // считываем студентов
    void readStudents(string fileName)
    {
        // TO DO
    }

    // считываем преподавателей
    void readTutors(string fileName)
    {
        ifstream fin(fileName.c_str());
        int n, experience, age;
		fin >> n;
        bool gender;
        string name;
        for (int i = 0; i < n; i++)
        {
            fin >> name >> age >> gender >> experience;
            people.push_back(
                new Teacher(name, age, gender, experience)
            );
        }
    }

    void chargeGrants()
    {
        for (int i = 0; i < people.size(); i++)
            pay(people[i]);
    }

};


void sampleOverride() 
{
    Student Kate("Kate", 20, 1), Bill("Bill", 19, 0);
    
	// Kate.operator+(Bill);
	Person child = Kate + Bill;
	
	
    Person child2 = Kate.operator+(Bill);
    child.print();
}



void samplePolymorphism()
{
    Sponsor Potanin;
    Potanin.chargeGrants();
}


int main()
{
    samplePolymorphism();
    // sampleOverride();
}

